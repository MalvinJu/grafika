#include "Point.h"

Point::Point() {
	setPoint(0,0);
}

Point::Point(int x, int y) {
	setPoint(x,y);
} 	

void Point::setPoint(int x, int y) {
	this->x = x;
	this->y = y;
} 

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void swap (int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void Point::swapPoint(Point *P) {
	swap(&x, &P->x);
	swap(&y, &P->y);
}

