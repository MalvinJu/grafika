#include "shape.h"
#include "Circle.h"
#include "Screen.h"
#include "parasut.h"
#include "HalfCircle.h"
#include <iostream>
using namespace std;

Shape tail,body,front,wing, baling1, baling2,baling3,baling4;
Shape bodyHuman, tali; Circle headHuman;
HalfCircle parasut;
Color white(255,255,255);
Color z(0,255,050);
Color a(100,100,100);
Color black(0,100,0);
Point pPoros(37,560);

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
	vector<Point> nodeTemplate;
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
		//cout << newx << " " << newy << endl;
	}
	
	//createShape
	Shape front(nodeScaling, border);
	front.setFillColor(fill);
	//setPosition
	//cout << "last : " << front.floodfill_seed.getX() << " " << front.floodfill_seed.getY() << endl;
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

Circle makeRoda (Point start,int r){
	Point pCircle(19,12);
	int scaleFactor = 8;	 
	pCircle.setPoint(pCircle.getX()*scaleFactor, pCircle.getY()*scaleFactor); 
	pCircle.setPoint(pCircle.getX() + start.getX(), pCircle.getY() + start.getY()); 
	Circle roda(pCircle,r,Color(255,255,255));
	return roda;
}

Shape makeCannon(Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(0,0));
    nodeTemplate.push_back(Point(0,80));
    nodeTemplate.push_back(Point(60,80)); 
	nodeTemplate.push_back(Point(60,0));
	int scaleFactor = 1;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	
	Shape cannon(nodeScaling, border);
	cannon.setFillColor(fill);
	//setPosition
	cannon.moveBy(start.getX(),start.getY());
	return cannon;
}

Shape makeBullet(Point start, Color border, Color fill){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(0,0));
    nodeTemplate.push_back(Point(0,5));
    nodeTemplate.push_back(Point(2,5)); 
	nodeTemplate.push_back(Point(2,0));
	int scaleFactor = 1;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	
	Shape cannon(nodeScaling, border);
	cannon.setFillColor(fill);
	//setPosition
	cannon.moveBy(start.getX(),start.getY());
	return cannon;
}

void *shootBullet(void *args){
	int x_peluru = *((int *) args);
	x_peluru +=30;
	Shape Bullet = makeBullet(Point(x_peluru, screen.getHeight()-120), white, z);
	Bullet.draw();
	while(Bullet.edges[2].getY()-10>0){
		usleep(1000);
		Bullet.moveBy(0, -1);
	}
	
}

Shape makeBaling2 (Point start, Color border, Color fill,int n){
	vector<Point> nodeTemplate;
	nodeTemplate.push_back(Point(2,42));
	nodeTemplate.push_back(Point(3,40));
	nodeTemplate.push_back(Point(4,42));
	nodeTemplate.push_back(Point(2,42));
	nodeTemplate.push_back(Point(2,44));
	nodeTemplate.push_back(Point(4,44));
	nodeTemplate.push_back(Point(4,42));
	
	int scaleFactor = 4;
	int newx,newy;
	vector<Point> nodeScaling;
	for(int i =0; i < nodeTemplate.size(); i++){
		newx = nodeTemplate[i].getX() * scaleFactor;
		newy = nodeTemplate[i].getY() * scaleFactor;
		nodeScaling.push_back(Point(newx,newy));
	}
	
	//createShape
	Shape baling2(nodeScaling, border);
	//baling2.setFillColor(fill);
	//setPosition
	baling2.moveBy(start.getX(),start.getY());
	//turn
	baling2.Rotate(n*90);
	if(n==1){
		baling2.moveBy((-3)*scaleFactor,(-3)*scaleFactor);
	}
	else if(n==2){
		baling2.moveBy(0,(-6)*scaleFactor);
	}
	else if(n==3){
		baling2.moveBy(3*scaleFactor,(-3)*scaleFactor);
	}
	
	return baling2;
}


void *spin_baling(void *args){
	while(1){
		baling1.RotatePoros(30, pPoros);
		baling2.RotatePoros(30, pPoros);
		baling3.RotatePoros(30, pPoros);
		baling4.RotatePoros(30, pPoros);
		usleep(100000);
	}
}

void *plane_fly(void *args){
    int i;
    Point start;
    start = *((Point *) args);
    
	baling1 = makeBaling2(start,white,a,0);
	baling2 = makeBaling2(start,white,a,1);
	baling3 = makeBaling2(start,white,a,2);
	baling4 = makeBaling2(start,white,a,3);

	front = makePlaneFront(start,white,z);
	body = makePlaneBody(start,white,z);
	tail = makePlaneTail(start,white,z);
	

	i=0;//counter derajat putaran pesawat
	int x; //poros putaran pesawat
	x=210;
	
	//gerakan awal rotasi pesawat
	while (i<=90){
		front.PlaneParabola(1,Point(x,300));
		//front.moveBy(10,0);
		tail.PlaneParabola(1,Point(x,300));
		//tail.moveBy(10,0);
		body.PlaneParabola(1,Point(x,300));
		//body.moveBy(10,0);
		if(i==60) break;
		baling1.PlaneParabola(1,Point(x,300));
		baling2.PlaneParabola(1,Point(x,300));
		baling3.PlaneParabola(1,Point(x,300));
		baling4.PlaneParabola(1,Point(x,300));
		pPoros.rotatePoros(1, Point(x,300));
		i++;
	}
		front.moveBy(10,10);
		body.moveBy(0,10);  
		tail.moveBy(5,8); 
		//ROTATE
		front.Rotate(30);
		body.Rotate(45);
		tail.Rotate(30);
		usleep(200000);
		
		//parasut
		headHuman = makeHead(start,20,z);
		bodyHuman = makeBody(start,white,z);
		parasut = makeParasut(start,50,z);
		tali = makeTali(start,white,z);
		while(1){
		parasut.moveBy(0,1);
		tali.moveBy(0,1);
		headHuman.moveBy(0,1);
		bodyHuman.moveBy(0,1);
		//tail.moveBy(1,0);
	}
	x=x+300;
	i = 0;
	//gerakan rotasi pesawat
	while(1){
		while (i<=180&&front.edges[0].getX()+240<screen.getWidth()){
			front.PlaneParabola(-1,Point(x,300));
			//front.moveBy(10,0);
			tail.PlaneParabola(-1,Point(x,300));
			//tail.moveBy(10,0);
			body.PlaneParabola(-1,Point(x,300));
			//body.moveBy(10,0);
			
			baling1.PlaneParabola(-1,Point(x,300));
			baling2.PlaneParabola(-1,Point(x,300));
			baling3.PlaneParabola(-1,Point(x,300));
			baling4.PlaneParabola(-1,Point(x,300));
			pPoros.rotatePoros(-1, Point(x,300));
			i++;
		}
		i=0;
		x=x+300;
		while (i<=180&&front.edges[0].getX()+240<screen.getWidth()){
			front.PlaneParabola(1,Point(x,300));
			//front.moveBy(10,0);
			tail.PlaneParabola(1,Point(x,300));
			//tail.moveBy(10,0);
			body.PlaneParabola(1,Point(x,300));
			//body.moveBy(10,0);
			
			baling1.PlaneParabola(1,Point(x,300));
			baling2.PlaneParabola(1,Point(x,300));
			baling3.PlaneParabola(1,Point(x,300));
			baling4.PlaneParabola(1,Point(x,300));
			pPoros.rotatePoros(1, Point(x,300));
			i++;
		}
		i=0;
		x=x+300;
		if(front.edges[0].getX()+240>=screen.getWidth()){
			tail.erase();
			front.erase();
			body.erase();
			baling1.erase();
			baling2.erase();
			baling3.erase();
			baling4.erase();
			start.setPoint(10,550);
			x=210;
			front = makePlaneFront(start,white,z);
			body = makePlaneBody(start,white,z);
			tail = makePlaneTail(start,white,z);
			baling1 = makeBaling2(start,white,a,0);
			baling2 = makeBaling2(start,white,a,1);
			baling3 = makeBaling2(start,white,a,2);
			baling4 = makeBaling2(start,white,a,3);
			while (i<=90){
				front.PlaneParabola(1,Point(x,300));
				//front.moveBy(10,0);
				tail.PlaneParabola(1,Point(x,300));
				//tail.moveBy(10,0);
				body.PlaneParabola(1,Point(x,300));
				//body.moveBy(10,0);
				
				baling1.PlaneParabola(1,Point(x,300));
				baling2.PlaneParabola(1,Point(x,300));
				baling3.PlaneParabola(1,Point(x,300));
				baling4.PlaneParabola(1,Point(x,300));
				pPoros.rotatePoros(1, Point(x,300));
				i++;
			}
			x=x+300;
			i = 0;			
		}
	}
}
