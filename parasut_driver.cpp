#include "parasut.h"
#include <iostream>
using namespace std;
Screen screen;
		 

int main(){
	screen.ClearScreen();
	Shape body;
	Shape tali;
	Circle head;
	HalfCircle parasut;

	Point start(100,100);
	Color white(255,255,255);
	Color z(0,255,050);
	head = makeHead(start,20,z);
	body = makeBody(start,white,z);
	parasut = makeParasut(start,50,z);
	tali = makeTali(start,white,z);
	parasut.draw();
	tali.draw();
	head.draw();
	body.draw();
	//sleep(10);
	while(1){
		parasut.moveBy(0,1);
		tali.moveBy(0,1);
		head.moveBy(0,1);
		body.moveBy(0,1);
		//tail.moveBy(1,0);
	}
}

