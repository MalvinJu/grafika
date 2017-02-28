#ifndef __QUADRATIC__
#define __QUADRATIC__
#include "Point.h"
#include "Color.h"
#include "Screen.h"
#include <vector>

using namespace std;

class QuadraticEquation{

public:
	QuadraticEquation ();
	QuadraticEquation (int a, int b, int c);
	void plotPointQuadratic (Point P, int width);

private:
	int a;	//a Koefisien x^2
	int b;	//b Koefisien x
	int c;	//c koefisien
};

#endif