#include "Plane.h"
#include <iostream>
#include <pthread.h>
#include <termios.h>
using namespace std;

//GLOBAL
Screen screen;


static struct termios old, news;

int x_peluru, y_peluru;
bool isCollide = false;
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


//COMMAND COMPILE
// g++ -o planetest *.h circle.cpp shape.cpp Point.cpp LineDrawer.cpp Color.cpp Plane_driver.cpp Screen.cpp -std=c++11 -pthread

void drawBackground(){
    for(int i =0; i<screen.getWidth(); i++){
        for(int j=0; j<screen.getHeight(); j++){
          screen.setColor(j,i, Color(0,0,0));          
        }
    }
}


int main(){
	screen.ClearScreen();
	drawBackground();
	
	Point start(25,400);

	int i;
	
	pthread_t plane_thread;
    Point *argu = (Point *)malloc(sizeof(*argu));
	*argu = start;
	int ra = pthread_create(&plane_thread, NULL, plane_fly, argu);
	pthread_t baling_thread;
	int baling = pthread_create(&baling_thread, NULL, spin_baling, argu);
	Shape Cannon = makeCannon(Point(screen.getWidth()/2,screen.getHeight()-90), white, a);
	int posCannon = screen.getWidth()/2;
	while (1){
		int c = getch();
        int n;
        
        switch(c){
            case 32 :
            {
                //shoot
                //Create another thread for bullet
                
                pthread_t thread;
                int *arg = (int *)malloc(sizeof(*arg));
                *arg = posCannon;
                usleep(10000);
                int rc = pthread_create(&thread, NULL, shootBullet, arg);
                break;
                
            }
            case 27 :
                
                n = getch();
                n = getch();
                if(n==68){
                    //go left
                    Cannon.moveBy(-10, 0);
                    posCannon-=10;
                } else if(n==67){
                    //go right
                    Cannon.moveBy(10, 0);
                    posCannon+=10;
                }
                break;
        }
	}
	/*
	while(1){
		//baling1.Rotate(30);
			
		baling1.RotatePoros(30,pPoros);
		baling2.RotatePoros(30,pPoros);
		baling3.RotatePoros(30,pPoros);
		baling4.RotatePoros(30,pPoros);
			
		outerRoda.draw();
		innerRoda.draw();
		tail.draw();
		body.draw();
		front.draw();
		wing.draw();
		
		usleep(100000);
	}
	sleep(10);
		/*while(1){
			tail.moveBy(1,0);
		}*/
}

