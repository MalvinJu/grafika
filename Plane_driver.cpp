#include "Plane.h"
#include <iostream>
using namespace std;
Screen screen;
			 
Color white(255,255,255);	
Circle outerRoda, innerRoda;
Shape baling1, baling2,baling3,baling4;
Shape tail,body,front,wing;

int main(){
	screen.ClearScreen();
		
		
	Point start(100,100);
		
	Color z(0,255,050);
	Color a(100,100,100);
	Color black(0,100,0);
	
	outerRoda = makeRoda(start,8);
	innerRoda = makeRoda(start,4);
	
	baling1 = makeBaling2(start,white,a,0);
	baling2 = makeBaling2(start,white,a,1);
	baling3 = makeBaling2(start,white,a,2);
	baling4 = makeBaling2(start,white,a,3);
		
	Point pPoros(112,220);
	tail = makePlaneTail(start,white,z);
	body = makePlaneBody(start,white,z);
	front = makePlaneFront(start,white,z);
	wing = makePlaneWing(start,white,z);
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

