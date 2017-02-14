#include "shape.h"
#include "Circle.h"
#include "HalfCircle.h"
#include "Screen.h"
#include <iostream>
using namespace std;

HalfCircle makeParasut (Point start, int r, Color fill){
	Point pCircle(10,5);
	int scaleFactor = 8;	 
	pCircle.setPoint(pCircle.getX()*scaleFactor, pCircle.getY()*scaleFactor); 
	pCircle.setPoint(pCircle.getX() + start.getX(), pCircle.getY() + start.getY()); 
	HalfCircle Parasut(pCircle,r,Color(255,255,255));
	Parasut.setFillColor(fill);
	return Parasut;
}
Circle makeHead (Point start,int r, Color fill){
	Point pCircle(10,10);
	int scaleFactor = 8;	 
	pCircle.setPoint(pCircle.getX()*scaleFactor, pCircle.getY()*scaleFactor); 
	pCircle.setPoint(pCircle.getX() + start.getX(), pCircle.getY() + start.getY()); 
	Circle head(pCircle,r,Color(255,255,255));
	head.setFillColor(fill);
	return head;
}

Shape makeTali (Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(3,4)); nodeTemplate.push_back(Point(8,6)); 
	nodeTemplate.push_back(Point(8,6)); nodeTemplate.push_back(Point(13,4)); 
	
	int scaleFactor = 10;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	//createShape
	Shape tali(nodeScaling, border);
	//body.setFillColor(fill);
	//setPosition
	tali.moveBy(start.getX(),start.getY());
	
	return tali;
}

Shape makeBody(Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(10,13)); nodeTemplate.push_back(Point(10,19)); 
	nodeTemplate.push_back(Point(10,13)); nodeTemplate.push_back(Point(8,15)); 
	nodeTemplate.push_back(Point(10,13)); nodeTemplate.push_back(Point(12,15)); 
	nodeTemplate.push_back(Point(12,15)); nodeTemplate.push_back(Point(10,13));
	nodeTemplate.push_back(Point(10,13)); nodeTemplate.push_back(Point(10,19));
	nodeTemplate.push_back(Point(10,19)); nodeTemplate.push_back(Point(8,22));
	nodeTemplate.push_back(Point(10,19)); nodeTemplate.push_back(Point(12,22));
	nodeTemplate.push_back(Point(12,22)); nodeTemplate.push_back(Point(10,19));
	
	int scaleFactor = 8;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	//createShape
	Shape body(nodeScaling, border);
	//body.setFillColor(fill);
	//setPosition
	body.moveBy(start.getX(),start.getY());
	
	return body;
}
/*
Shape makePlaneTail(Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(0,2)); nodeTemplate.push_back(Point(2,2)); 
	nodeTemplate.push_back(Point(2,2)); nodeTemplate.push_back(Point(5,6)); 
	nodeTemplate.push_back(Point(5,6)); nodeTemplate.push_back(Point(9,7)); 
	nodeTemplate.push_back(Point(9,7)); nodeTemplate.push_back(Point(1,7));
	nodeTemplate.push_back(Point(1,7)); nodeTemplate.push_back(Point(0,2));
	
	int scaleFactor = 8;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	//createShape
	Shape tail(nodeScaling, border);
	tail.setFillColor(fill);
	//setPosition
	tail.moveBy(start.getX(),start.getY());
	
	return tail;
}

Shape makePlaneBody(Point start, Color border, Color fill){
	vector<Pointa> nodeTemplate;
	nodeTemplate.push_back(Point(0,7)); 
	nodeTemplate.push_back(Point(1,7)); 
	nodeTemplate.push_back(Point(7,7));
	nodeTemplate.push_back(Point(18,7));
	nodeTemplate.push_back(Point(18,11));
	nodeTemplate.push_back(Point(17,12));
	nodeTemplate.push_back(Point(15,12));
	nodeTemplate.push_back(Point(9,21));
	nodeTemplate.push_back(Point(5,21));
	nodeTemplate.push_back(Point(8,12));
	nodeTemplate.push_back(Point(9,11));
	nodeTemplate.push_back(Point(0,11));
	nodeTemplate.push_back(Point(0,7));
	
	int scaleFactor = 8;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	
	//createShape
	Shape body(nodeScaling, border);
	body.setFillColor(fill);
	//setPosition
	body.moveBy(start.getX(), start.getY());
	
	return body;
}

Shape makePlaneFront(Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	//kaca
    nodeTemplate.push_back(Point(18,7));
    nodeTemplate.push_back(Point(19,7));
    nodeTemplate.push_back(Point(20,6)); 
	nodeTemplate.push_back(Point(22,6)); 
	nodeTemplate.push_back(Point(23,7));
	nodeTemplate.push_back(Point(25,7)); 
	nodeTemplate.push_back(Point(23,7));
	nodeTemplate.push_back(Point(22,8));
	nodeTemplate.push_back(Point(20,8));
	nodeTemplate.push_back(Point(19,7)); 
	
	//muterbalik gambar dr point yg lain
	nodeTemplate.push_back(Point(20,8));
	nodeTemplate.push_back(Point(22,8));
	nodeTemplate.push_back(Point(23,7));
	nodeTemplate.push_back(Point(25,7));
	nodeTemplate.push_back(Point(30,9));
	nodeTemplate.push_back(Point(25,11));
	nodeTemplate.push_back(Point(18,11));
	
	
	
	int scaleFactor = 8;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
		cout << newx << " " << newy << endl;
	}
	
	//createShape
	Shape front(nodeScaling, border);
	front.setFillColor(fill);
	//setPosition
	cout << "last : " << front.floodfill_seed.getX() << " " << front.floodfill_seed.getY() << endl;
	front.moveBy(start.getX(),start.getY());
	return front;
}		
	 
Shape makePlaneWing (Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(10,7));
    nodeTemplate.push_back(Point(17,0));
    nodeTemplate.push_back(Point(19,0)); 
	nodeTemplate.push_back(Point(18,7));
	
	int scaleFactor = 8;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	
	//createShape
	Shape wing(nodeScaling, border);
	wing.setFillColor(fill);
	//setPosition
	wing.moveBy(start.getX(),start.getY());
	return wing;
}	 

*/