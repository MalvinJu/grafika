#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <termios.h>
#define MAX_NUM 1 << 8
#define MAX_KAL 20
#define PIXEL 800
#define EPS 1e-7
#define nArrKalimat 14

#define height 500
#define width 833.33

typedef struct {
	int x, y;
} Point;
char kalimat[MAX_NUM][MAX_NUM];
int RK[MAX_KAL][PIXEL][PIXEL];
int GK[MAX_KAL][PIXEL][PIXEL];
int BK[MAX_KAL][PIXEL][PIXEL];
int HK[MAX_KAL];
int WK[MAX_KAL];
#define initH 100
#define initW 100

void init();
void clearScr();
void swap(int *a, int *b);
void gambarGaris(int x1, int y1, int x2, int y2, int tebal);
void gambarPoint(int x,  int y);
void gambarPesawat(int x, int y);

int fbfd = 0;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long int screensize = 0;
char *fbp = 0;
long int location = 0;

int nidxlooping = 150, idxloop = 0;
int idxplane_x;

Point T_1_now, T_2_now;
typedef struct {
	char jenis; //jenis garis yang digambar, s for straight, d for dashed, and c for curve/circle
	int x1;
	int y1;
	int x2;
	int y2;
} LINES;



int main()
{
	// INISIASI
	init();
	T_1_now.x = T_1_now.y = T_2_now.x = T_2_now.y = -1;
	idxplane_x = -50;
	gambarPesawat(idxplane_x,50);
	while(idxloop <= nidxlooping){
		// ========== MOVEMENT 
		
		idxplane_x += 10;
		if (idxplane_x >= 900){
			idxplane_x = -100;
		}
		gambarPesawat(idxplane_x,50);
		nanosleep((const struct timespec[]){{0,100000000L}},NULL);
		clearScr();
		idxloop++;
	}
	munmap(fbp, screensize);
	close(fbfd);
	return 0;
}

void init(){
	//============ Init FrameBuffer
	// Open the file for reading and writing
	fbfd = open("/dev/fb0", O_RDWR);
	if (fbfd == -1) {
		perror("Error: cannot open framebuffer device");
		exit(1);
	}
	printf("The framebuffer device was opened successfully.\n");

	// Get fixed screen information
	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
		perror("Error reading fixed information");
		exit(2);
	}

	// Get variable screen information
	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
		perror("Error reading variable information");
		exit(3);
	}

	printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

	// Figure out the size of the screen in bytes
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	// Map the device to memory
	fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	if (*fbp == -1) {
		perror("Error: failed to map framebuffer device to memory");
		exit(4);
	}
	printf("The framebuffer device was mapped to memory successfully.\n");
	//============ EndOF Init FrameBuffer
}

void clearScr(){
	for (int h = 0; h < height; h++)
		for (int w = 0; w < width; w++) {

			location = (w + initW + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
				(h + initH + vinfo.yoffset) * finfo.line_length;

			if (vinfo.bits_per_pixel == 32) {
				*(fbp + location) = 255;        // Some blue
				*(fbp + location + 1) = 255; //15+(x-100)/2;     // A little green
				*(fbp + location + 2) = 255; //200-(y-100)/5;    // A lot of red
				*(fbp + location + 3) = 0;      // No transparency
			}
		}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void gambarGaris(int x1, int y1, int x2, int y2, int tebal){
	for(int t1 = -tebal; t1 <= tebal; ++t1){
		for(int t2 = -tebal; t2 <= tebal; ++t2){
			int xawal = x1 < x2 ? x1 : x2;
			int xakhir = x2 > x1 ? x2 : x1;

			int yawal = y1, yakhir = y2;
			if(xawal != x1){
				swap(&yawal, &yakhir);
			}

			xawal += t1;
			xakhir += t1;
			yawal += t2;
			yakhir += t2;

			int selisihAbsX = xawal - xakhir >= 0 ? xawal - xakhir : xakhir - xawal;
			int selisihAbsY = yawal - yakhir >= 0 ? yawal - yakhir : yakhir - yawal;

			//bagi kasus kalo selisihnya 0
			if(selisihAbsX == 0){
				if(yawal > yakhir) swap(&yawal, &yakhir);
				for(int i = yawal; i <= yakhir; ++i){
					gambarPoint(xawal, i);
				}
			}
			else if (selisihAbsY == 0){
				if(xawal > xakhir) swap(&xawal, &xakhir);
				for(int i = xawal; i <= xakhir; ++i){
					gambarPoint(i, yawal);
				}
			}
			else if(selisihAbsY < selisihAbsX){
				if(xawal > xakhir) swap(&xawal, &xakhir), swap(&yawal, &yakhir);
				int deltaY = yakhir - yawal;
				int deltaX = xakhir - xawal;
				for(int i = 0; i <= deltaX; ++i){
					int modY = (deltaY * i) % deltaX;
					int ynow = yawal + (deltaY * i) / deltaX + (modY * 2) / deltaX;
					gambarPoint(xawal + i, ynow);
				}
			}
			else{
				if(yawal > yakhir) swap(&xawal, &xakhir), swap(&yawal, &yakhir);
				int deltaY = yakhir - yawal;
				int deltaX = xakhir - xawal;
				for(int i = 0; i <= deltaY; ++i){
					int modX = (deltaX * i) % deltaY;
					int xnow = xawal + (deltaX * i) / deltaY + (modX * 2) / deltaY;
					gambarPoint(xnow, yawal + i);
				}
			}

		}
	}
}

void gambarPoint(int x, int y){
	if (y < height && x < width && y >= 0 && x >= 0){
		int location = (x + initW + vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
			(y + initH + vinfo.yoffset) * finfo.line_length;

		if (vinfo.bits_per_pixel == 32) {
			*(fbp + location) = 200;        // Some blue
			*(fbp + location + 1) = 0; //15+(x-100)/2;     // A little green
			*(fbp + location + 2) = 0; //200-(y-100)/5;    // A lot of red
			*(fbp + location + 3) = 0;      // No transparency
		}
	}
}

void gambarPesawat(int x, int y) {
	Point P[15];
	int tebal = 2;

	// 0,0
	P[0].x = x;	P[0].y = y;

	//100, 0
	P[1].x = P[0].x + 100;
	P[1].y = P[0].y; 

	//25, 30
	P[2].x = P[0].x + 25;
	P[2].y = P[0].y + 30;

	//150, 30
	P[3].x = P[2].x + 125;
	P[3].y = P[2].y;

	//0, -25
	P[4].x = P[0].x;
	P[4].y = P[0].y - 25;

	//20, -25
	P[5].x = P[4].x + 20;
	P[5].y = P[4].y;

	//25, 0
	P[6].x = P[5].x + 5;
	P[6].y = P[0].y;

	//50, 0
	P[7].x = P[0].x + 50;
	P[7].y = P[0].y;

	//45, -20
	P[8].x = P[0].x + 45;
	P[8].y = P[0].y - 20;

	//65, -20
	P[9].x = P[8].x + 20;
	P[9].y = P[8].y;

	//80, 0
	P[10].x = P[0].x + 80;
	P[10].y = P[0].y;

	//50, 15
	P[11].x = P[7].x;
	P[11].y = P[7].y + 15;

	//45, 40
	P[12].x = P[8].x;
	P[12].y = P[8].y + 60;

	//65, 40
	P[13].x = P[9].x;
	P[13].y = P[9].y + 60;

	//80, 15
	P[14].x = P[10].x;
	P[14].y = P[10].y + 15;

	//max : 150, 40
	//min : 0, -25

	int awal[] = {0, 0, 2, 1, 0, 4, 5, 7, 8, 9, 11, 12, 13};
	int akhir[] = {1, 2, 3, 3, 4, 5, 6, 8, 9, 10, 12, 13, 14};
	for(int i = 0;i < 13; ++i){
		gambarGaris(P[awal[i]].x, P[awal[i]].y, P[akhir[i]].x, P[akhir[i]].y, tebal / 2);
	}   
}
