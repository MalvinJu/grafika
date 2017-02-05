#include <stdlib.h>
#include <stdio.h>
#include "Point.h"
#include "Screen.h"

Screen screen;

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
	for (i = 0;i < n-1;i++) {
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

void floodFill8Seed (Point P, Color cBorder, Color cNew) {
	if (!cBorder.isSame(screen.getColor(P.getY(), P.getX()))) {
		screen.setColor(P.getY(), P.getX(), cNew);

	    floodFill8(P.getX() + 1, p.getY()    , cBorder, cNew);
	    floodFill8(P.getX() - 1, p.getY()    , cBorder, cNew);
	    floodFill8(P.getX()    , p.getY() + 1, cBorder, cNew);
	    floodFill8(P.getX()    , p.getY() - 1, cBorder, cNew);
	    floodFill8(P.getX() + 1, p.getY() + 1, cBorder, cNew);
	    floodFill8(P.getX() - 1, p.getY() - 1, cBorder, cNew);
	    floodFill8(P.getX() - 1, p.getY() + 1, cBorder, cNew);
	    floodFill8(P.getX() + 1, p.getY() - 1, cBorder, cNew);
  }
}