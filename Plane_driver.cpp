#include "Plane.h"
#include <iostream>
using namespace std;
Screen screen;
		 

int main(){
	screen.ClearScreen();
	Shape tail,body,front,wing;
	Circle outerRoda, innerRoda;
	
	Point start(100,100);
	Color white(255,255,255);
	Color z(0,255,050);
	tail = makePlaneTail(start,white,z);
	body = makePlaneBody(start,white,z);
	front = makePlaneFront(start,white,z);
	wing = makePlaneWing(start,white,z);
	outerRoda = makeRoda(start,8);
	innerRoda = makeRoda(start,4);
	tail.draw();
	body.draw();
	front.draw();	
	wing.draw();
	innerRoda.draw();
	outerRoda.draw();
	sleep(10);
	/*while(1){
		tail.moveBy(1,0);
	}*/
}

