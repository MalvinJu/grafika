#include "Point.h"
#include "Color.h"
#include "Screen.h"
#include "Quadratic.h"
#include <vector>

using namespace std;


QuadraticEquation::QuadraticEquation () {
	a = -1;
	b = 0;
	c = 0;
}

QuadraticEquation::QuadraticEquation (int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

void QuadraticEquation::plotPointQuadratic (Point P, int width) {
	for (int i=-width/2;i<width/2;i+=3) {
		int y = a*i*i + b*i + c;

		//draw here
	}
}

