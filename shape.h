#ifndef __SHAPE__
#define __SHAPE__
#include "LineDrawer.h"
#include "Point.h"
#include <vector>
#include "AbstractShape.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <iostream>
class Shape: public AbstractShape{

public:

	//Constructor, 
	//starting edge is collection of point that make the shape
	Shape();
	Shape(vector<Point>& starting_edge, Color C );
	Shape& operator=(const Shape &obj);
	Shape(const Shape &obj);
	//Destructor
	~Shape();

	//set floodfill color
	void setFillColor(Color C);
	//set Border Color to color c
	void setBorderColor(Color c);
	
	//Move the object by delta
	//deltaX : move the object in X axis by delta X
	//deltaY : move the object in Y axis by delta Y
	void moveBy(int deltaX, int deltaY);


	//rotate the object by theta degree clockwise with 
	//cePoint center as  center of rotation
	void Rotate(int theta);
	void RotatePoros(int theta,Point poros);
	void PlaneParabola(int theta,Point poros);
	

	//set the center of rotation to P
	void setCenter(Point P);

	void erase();
	void draw();
	Point floodfill_seed;
	vector<Point> edges;
	Point center;
	LineDrawer linedrawer;
	Color Border;
	Color Fill;

};

#endif                                                   
