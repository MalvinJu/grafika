#include <stdio.h>
#include <stdlib.h>
#include "Screen.h"
#include <vector>
#include <string>
#include <omp.h>
#include <termios.h>
#include <algorithm>
using namespace std;

Screen screen;

struct{
    int height,width;
    vector< vector<Color> > pixel;
} bmp;

static struct termios old, news;


void readBMP(string filename);
void zoomin();
void zoomout();
void flush();

/* Initialize new terminal i/o settings */
void initTermios(int echo);

/* Restore old terminal i/o settings */
void resetTermios(void);

/* Read 1 character - echo defines echo mode */
char getch_(int echo);

/* Read 1 character without echo */
char getch(void);


int main(){
    omp_set_num_threads(7);
    readBMP("tiger.bmp");
	screen.ClearScreen();

	
	for(int i=0 ;i<bmp.height;i++){
		for(int j=0; j<bmp.width; j++){
        	screen.setColor(i,j,bmp.pixel[i][j]);
		}
        
	}

    while(1){
        int c = getch();
        int n;
        
        switch(c){
            
            case 27 :
                
                n = getch();
                n = getch();
                if(n==68){
                    //zoom in
                    zoomout();
                    screen.ClearScreen();
                    flush(); 
                    

                } else if(n==67){
                    //zoom in

                    zoomin();
                    screen.ClearScreen();
                    flush();

                }
                break;
        }
    }


}


void readBMP(string filename)
{
    //membaca file BMP dan menyimpan ke variable glocal bmp
    int i;
    FILE* f = fopen(filename.c_str(), "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width,height;
    bmp.width = width = *(int*)&info[18];
    bmp.height = height =  *(int*)&info[22];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel

    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

    int row=-1;
    int colomn=0;
    bmp.pixel.resize(height);

    //Somehow hasil BMP yang di read terbalik, jadinya dikasih "trick"
    for(i = 0; i < size; i += 3)
    {   
        if(i%(width*3) == 0){
            row++;
            bmp.pixel[bmp.height-row-1].resize(width);
            colomn=0;
        }
        bmp.pixel[bmp.height-row-1][colomn] = Color(data[i+2],data[i+1],data[i]);
        colomn++;
    }

    
}

void zoomin(){
    //memakai zero order hold


    //zoom colomn
    bmp.width = bmp.width*2 - 1;

    for(int row=0; row<bmp.height; row++){
        vector<Color>::iterator it;
        it = bmp.pixel[row].begin();
        
        for(int colomn = 0; colomn < bmp.width; colomn+=2 ){
            it = bmp.pixel[row].begin();
            int red,green,blue;
            red = (bmp.pixel[row][colomn].getRed() + bmp.pixel[row][colomn+1].getRed()) / 2;
            blue = (bmp.pixel[row][colomn].getBlue() + bmp.pixel[row][colomn+1].getBlue()) / 2;
            green = (bmp.pixel[row][colomn].getGreen() + bmp.pixel[row][colomn+1].getGreen()) / 2;
            bmp.pixel[row].insert(it+colomn+1,Color(red,green,blue));
            
        }
    }


    //zoom row
    bmp.height = bmp.height*2 - 1;
    for(int row=0; row<bmp.height-1; row+=2){

        vector< vector<Color> >::iterator it;
        it = bmp.pixel.begin();

        bmp.pixel.insert(it+row+1,  vector<Color>());

        bmp.pixel[row+1].resize(bmp.width);

        #pragma omp parallel for
        for(int colomn = 0; colomn < bmp.width; colomn++ ){
            
            int red,green,blue;
            red = (bmp.pixel[row][colomn].getRed() + bmp.pixel[row+2][colomn+1].getRed()) / 2;
            blue = (bmp.pixel[row][colomn].getBlue() + bmp.pixel[row+2][colomn+1].getBlue()) / 2;
            green = (bmp.pixel[row][colomn].getGreen() + bmp.pixel[row+2][colomn+1].getGreen()) / 2;
            bmp.pixel[row+1][colomn] = Color(red,green,blue);
            
        }

    }
}

void zoomout(){
    bmp.height = (bmp.height+1)/2;

    for(int row=0;row<bmp.height;row++){
        bmp.pixel.erase(bmp.pixel.begin()+row+1);
    }
    bmp.height = bmp.pixel.size();

    bmp.width = (bmp.width+1)/2;

    for(int row=0; row<bmp.height; row++){
        for(int colomn=0;colomn<bmp.width;colomn++){
            bmp.pixel[row].erase(bmp.pixel[row].begin()+colomn+1);
        }    
    }
    
}

void flush(){
    #pragma omp parallel for
    for(int i=0 ;i<min(bmp.height,500);i++){
        for(int j=0; j<min(bmp.width,500); j++){
            screen.setColor(i,j,bmp.pixel[i][j]);
        }
        
    }
}

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  news = old; /* make new settings same as old settings */
  news.c_lflag &= ~ICANON; /* disable buffered i/o */
  news.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &news); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}