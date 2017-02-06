#include "Point.h"
#include "Color.h"
#include "Screen.h"
#include <iostream>
using namespace std;

Screen screen;
Color white(255,255,255);

void plotSlopPositiveLine (Point P1, Point P2, Color C) {
	int dX, dY, p;
	int i, j, x, y;

	dX = abs(P2.getX() - P1.getX());
	dY = abs(P2.getY() - P1.getY());
	i = P1.getX();
	j = P1.getY();
	
	if (dX >= dY) {
		p = 2*dY - dX;

		for (x=P1.getX(); x<=P2.getX(); x++) {
			screen.setColor(j, x, C);
			if (p >= 0) {
				p += 2* (dY - dX);
				i++;
				j++;
			}
			else {
				p += 2*dY;
				i++;
			}
		}
	}
	else {
		p = 2*dX - dY;

		for (y=P1.getY(); y<=P2.getY(); y++) {
			screen.setColor(y, i, C);
			if (p >= 0) {
				p += 2* (dX - dY);
				i++;
				j++;
			}
			else {
				p += 2*dX;
				j++;
			}
		}
	}
}

void plotSlopNegativeLine (Point P1, Point P2, Color C) {
	int dX, dY, p;
	int i, j, x, y;

	dX = abs(P2.getX() - P1.getX());
	dY = abs(P2.getY() - P1.getY());

	if (dX >= dY) {
		i = P1.getX();
		j = P1.getY();
		p = 2*dY - dX;		

		for (x=P1.getX(); x<=P2.getX(); x++) {
			screen.setColor(j, x, C);
			if (p >= 0) {
				p += 2* (dY - dX);
				i++;
				j--;
			}
			else {
				p += 2*dY;
				i++;
			}
		}
	}
	else {
		p = 2*dX - dY;
		i = P2.getX();
		j = P2.getY();

		for (y=P2.getY(); y<=P1.getY(); y++) {
			screen.setColor(y, i, C);
			if (p >= 0) {
				p += 2* (dX - dY);
				i--;
				j++;
			}
			else {
				p += 2*dX;
				j++;
			}
		}
	}
}

void plotVerticalLine (Point P1, Point P2, Color C) {
	int j;
	
	if (P2.getY() < P1.getY()) {
		P1.swapPoint(&P2);	
	}
	
	for(j = P1.getY() ; j <= P2.getY(); j++) {
		screen.setColor(j, P1.getX(), C);
	}
}

void drawBresenhamLine (Point P1, Point P2, Color C) {
	if (P1.getX() > P2.getX()) {
		P1.swapPoint(&P2); 
	}

	if ((P2.getX() >= P1.getX() && P1.getY() > P2.getY())) {
		plotSlopNegativeLine(P1,P2,C);
	}
	else if (P1.getX() == P2.getX()) {
		plotVerticalLine(P1,P2,C);
	}
	else {
		plotSlopPositiveLine(P1,P2,C);
	}
}

/*
*P : Array of Point
n : Array size
*/
void drawPolyline (int n, Point *P, Color C) {
	int i;
	for (i = 0;i < n-1;i=i+2) {
		drawBresenhamLine(P[i], P[i+1], C);
	}
}

/*
*P : Array of Point
n : Array size
*/
void drawPolygon (int n, Point *P, Color C) {
	drawBresenhamLine(P[n-1], P[0], C);
	drawPolyline(n, P, C);
}

void plot8pixel (Point P, int p, int q, Color C) {
	screen.setColor(P.getY()+q, P.getX()+p, C);
    screen.setColor(P.getY()+q, P.getX()-p, C);
    screen.setColor(P.getY()-q, P.getX()+p, C);
    screen.setColor(P.getY()-q, P.getX()-p, C);

    screen.setColor(P.getY()+p, P.getX()+q, C);
    screen.setColor(P.getY()+p, P.getX()-q, C);
    screen.setColor(P.getY()-p, P.getX()+q, C);
    screen.setColor(P.getY()-p, P.getX()-q, C);
}

void drawCircle (int radius, Point P, Color C) {
    int d, p, q;

    p = 0;
    q = radius;
    d = 3 - 2*radius;

    plot8pixel(P, p, q, C);

    while (p < q) {
        p++;
        if (d<0) {
            d = d + 4*p + 6;
        }
        else {
            q--;
            d = d + 4*(p-q) + 10;
        }

        plot8pixel(P, p, q, C);
    }
}

/*
x : kordinat x
y : kordinat y
cBorder : warna border poilgin
cNew : fill polygon

x dan y kordinat di dalam poligon
Still Segmentation Fault
*/
void floodFill4Seed (int x, int y, Color cBorder, Color cNew) {
	
	if (cBorder.isSame(screen.getColor(y, x))) {
		
	}
	else if (cNew.isSame(screen.getColor(y, x))) {
		
	}
	else if ((x>screen.getWidth() || x<0) || (y>screen.getHeight() || y<0)) {
		
	}
	else {
		screen.setColor(y, x, cNew);
		floodFill4Seed(x + 1, y	   , cBorder, cNew);
	    floodFill4Seed(x    , y - 1, cBorder, cNew);
	    floodFill4Seed(x , y+1    , cBorder, cNew);
	    floodFill4Seed(x - 1, y    , cBorder, cNew);
	}  
}

void drawPlane (Point start){
	int posx = start.getX();
    int posy = start.getY();
    int nPoint = 58;
    
    int newX, newY;
    
    Point *arrPoint = new Point[58];
    //tail 10
    arrPoint[0].setPoint(0,2); arrPoint[1].setPoint(2,2); 
    arrPoint[2].setPoint(2,2); arrPoint[3].setPoint(5,6); 
    arrPoint[4].setPoint(5,6); arrPoint[5].setPoint(9,8); 
    arrPoint[6].setPoint(9,8); arrPoint[7].setPoint(1,8); 
    arrPoint[8].setPoint(1,8); arrPoint[9].setPoint(0,2); 
    
    //body 28
    arrPoint[10].setPoint(0,7); arrPoint[11].setPoint(1,7); 
    arrPoint[12].setPoint(7,7); arrPoint[13].setPoint(19,7); 
    arrPoint[14].setPoint(23,7); arrPoint[15].setPoint(25,7); 
    arrPoint[16].setPoint(25,7); arrPoint[17].setPoint(30,9); 
    arrPoint[18].setPoint(30,9); arrPoint[19].setPoint(25,11);
    arrPoint[20].setPoint(25,11); arrPoint[21].setPoint(18,11);
    arrPoint[22].setPoint(18,11); arrPoint[23].setPoint(17,12);
    arrPoint[24].setPoint(17,12); arrPoint[25].setPoint(15,12);
    arrPoint[26].setPoint(15,12); arrPoint[27].setPoint(9,21);
    arrPoint[28].setPoint(9,21); arrPoint[29].setPoint(5,21);
    arrPoint[30].setPoint(5,21); arrPoint[31].setPoint(8,12);
    arrPoint[32].setPoint(8,12); arrPoint[33].setPoint(9,11);
    arrPoint[34].setPoint(9,11); arrPoint[35].setPoint(0,11);
    arrPoint[36].setPoint(0,11); arrPoint[37].setPoint(0,7);
    
    //kaca
    arrPoint[38].setPoint(19,7); arrPoint[39].setPoint(20,6);
    arrPoint[40].setPoint(19,7); arrPoint[41].setPoint(20,8);
    arrPoint[42].setPoint(22,6); arrPoint[43].setPoint(23,7);
    arrPoint[44].setPoint(22,8); arrPoint[45].setPoint(23,7);
    arrPoint[46].setPoint(20,6); arrPoint[47].setPoint(22,6);
    arrPoint[48].setPoint(20,8); arrPoint[49].setPoint(22,8);
    
		
	//sayap
	arrPoint[50].setPoint(10,7); arrPoint[51].setPoint(17,0);
	arrPoint[52].setPoint(17,0); arrPoint[53].setPoint(19,0);
	arrPoint[54].setPoint(19,0); arrPoint[55].setPoint(18,7);
		
		
	//roda
	arrPoint[56].setPoint(19,11); arrPoint[57].setPoint(19,12);
	Point p;//lingkaran
	p.setPoint(19,13);
	
	//scale
    int scaleFactor = 10;
    for(int i = 0; i<nPoint; i++){
		newX = arrPoint[i].getX() * scaleFactor;
		newY = arrPoint[i].getY() * scaleFactor;
		arrPoint[i].setPoint(newX, newY);
	}
	newX = p.getX() * scaleFactor;
	newY = p.getY() * scaleFactor;
	p.setPoint(newX, newY);
	
	//position
	for (int i = 0; i<nPoint; i++){
		newX = arrPoint[i].getX() + posx;
		newY = arrPoint[i].getY() + posy;		
		arrPoint[i].setPoint(newX,newY);
	}	
	newX = p.getX() + posx;
	newY = p.getY() + posy;
	p.setPoint(newX, newY);
	
	//draw
    drawPolyline(58,arrPoint,white);
	
	drawCircle (8,p,white);
	drawCircle (4,p,white);
}

int main(){
	Color red(225,0,0);
	Color lala(-36,20,60);
	Point start(100,100);
	drawPlane(start);
	floodFill4Seed(150,185,white,red);
	return 0;
}
