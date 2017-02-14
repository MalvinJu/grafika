#include "Plane.h"
#include <iostream>
using namespace std;
Screen screen;
		 

int main(){
	screen.ClearScreen();
	Shape tail,body,front,wing, baling1, baling2,baling3,baling4, balingtemp;
	Circle outerRoda, innerRoda;
	
	Point start(400,400);
	Color white(255,255,255);
	Color z(0,255,050);
	Color a(100,100,100);
	Color black(0,100,0);
	
	tail = makePlaneTail(start,white,z);
	while(1){
		tail.RotatePoros(1,Point(300,300)); usleep(5000);
	}
	/*body = makePlaneBody(start,white,z);
	front = makePlaneFront(start,white,z);
	wing = makePlaneWing(start,white,z);
	baling1 = makeBaling2(start,white,a,0);
	baling2 = makeBaling2(start,white,a,1);
	baling3 = makeBaling2(start,white,a,2);
	baling4 = makeBaling2(start,white,a,3);
	//balingtemp = makeBaling2(start,z,z,0);
	outerRoda = makeRoda(start,8);
	innerRoda = makeRoda(start,4);
	tail.draw();
	body.draw();
	front.draw();	
	wing.draw();
	innerRoda.draw();
	outerRoda.draw();
	baling1.draw();
	baling2.draw();
	baling3.draw();
	baling4.draw();
	int count = 13; int scale = 4; int i = 0;int iz = 0; int t = 1;
	
	usleep(500000);
	baling1.erase();
	/*while(i<count){
		baling1.draw();
		baling2.draw();
		baling3.draw();
		baling4.draw();
		
		usleep(200000);
		baling1.erase();
		baling2.erase();
		baling3.erase();
		baling4.erase();*/
				
		
		/*if(iz<3){
			//balingtemp.Rotate(30);sleep(200000);
			baling1.Rotate(30);
			baling2.Rotate(30);
			baling3.Rotate(30);
			baling4.Rotate(30);
		//sleep(200000);balingtemp.draw(); sleep(200000);
			iz++;
		}
		else{
			if(t>4){t=1;}
			else{t++;}
			iz=0;
		}
		
		//putar
		if(t==1){
			//balingtemp.moveBy((-1)*scale,(-1)*scale);
			baling1.moveBy((-1)*scale,(-1)*scale);body.draw();
			baling2.moveBy((1)*scale,(-1)*scale);body.draw();
			baling3.moveBy((1)*scale,(1)*scale);body.draw();
			baling4.moveBy((-1)*scale,(1)*scale);body.draw();
			//balingtemp.draw();
		}
		else if(t==2){
			baling1.moveBy(1*scale,(-1)*scale);
			baling2.moveBy(1*scale,(1)*scale);
			baling3.moveBy((-1)*scale,(1)*scale);
			baling4.moveBy((-1)*scale,(-1)*scale);
		}
		else if(t==3){
			baling1.moveBy(1*scale,1*scale);
			baling2.moveBy((-1)*scale,1*scale);
			baling3.moveBy((-1)*scale,(-1)*scale);
			baling4.moveBy(1*scale,(-1)*scale);
		}
		else if(t==4){
			baling1.moveBy(-1*scale,1*scale);
			baling2.moveBy(-1*scale,-1*scale);
			baling3.moveBy(1*scale,-1*scale);
			baling4.moveBy(1*scale,1*scale);
		}usleep(500000);
		//sleep(500);
		//baling2.moveBy(0,(-2)*scale);sleep(10);
		//baling3.moveBy(1*scale,(-1)*scale);sleep(10);
		//baling4.moveBy(
		i++;
	}*/
	//}
	sleep(10);
	/*while(1){
		tail.moveBy(1,0);
	}*/
}

