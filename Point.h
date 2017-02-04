#ifndef __Point__
#define __Point__

class Point{

public:
	Point();					//constructor
	Point(int x, int y); 		//constructor with initial x and y

	void setPoint(int x, int y); //set x and y
	int getX();
	int getY();
	void swapPoint(Point *P);

private:
	int x;
	int y;
};


#endif