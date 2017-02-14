#include "HalfCircle.h"

HalfCircle::HalfCircle(){}

HalfCircle::HalfCircle(Point P, int r, Color c ){

	Border = c;

	center = P;
	radius = r;
	draw();
}
HalfCircle::~HalfCircle(){
	erase();

}

void HalfCircle::moveBy(int deltaX, int deltaY){
	erase();
	center.moveBy(deltaX,deltaY);
	draw();
}

//rotate the object by theta degree clockwise
void HalfCircle::Rotate(int theta){
	//Well, we can say HalfCircle is constanlu rotating
}


void HalfCircle::erase(){
	linedrawer.drawHalfCircle(radius,center,Color(0,0,0));
	linedrawer.floodFill4Seed(center.getX(), center.getY()-5, Border, Color(0,0,0));
}
void HalfCircle::draw(){
	linedrawer.drawHalfCircle(radius, center, Border);
	linedrawer.floodFill4Seed(center.getX(), center.getY()-5, Border, Fill);
}

//set floodfill color
void HalfCircle::setFillColor(Color C){
	Fill = C;

}
//set Border Color to color c
void HalfCircle::setBorderColor(Color c){
	Border = c;
}