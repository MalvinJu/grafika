#ifndef __HalfCircle__
#define __HalfCircle__
#include "LineDrawer.h"
#include "Point.h"
#include <vector>
#include "AbstractShape.h"


class HalfCircle: public AbstractShape{

public:

	//Constructor, 
	//Point
	HalfCircle();
	HalfCircle(Point P, int r, Color c );
	//Destructor
	~HalfCircle();
	
	//set floodfill color
	void setFillColor(Color C);
	//set Border Color to color c
	void setBorderColor(Color c);

	//Move the object by delta
	//deltaX : move the object in X axis by delta X
	//deltaY : move the object in Y axis by delta Y
	void moveBy(int deltaX, int deltaY);


	//rotate the object by theta degree clockwise
	void Rotate(int theta);


//private:
	void erase();
	void draw();
	int radius;
	Point center;
	Color Fill;
	Color Border;
	LineDrawer linedrawer;

};

#endif                                                   
