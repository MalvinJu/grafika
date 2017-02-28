#include "shape.h"
#include "Circle.h"
#include "Screen.h"
#include <iostream>
using namespace std;

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

Circle makeRoda (Point start,int r){
	Point pCircle(19,12);
	int scaleFactor = 8;	 
	pCircle.setPoint(pCircle.getX()*scaleFactor, pCircle.getY()*scaleFactor); 
	pCircle.setPoint(pCircle.getX() + start.getX(), pCircle.getY() + start.getY()); 
	Circle roda(pCircle,r,Color(255,255,255));
	return roda;
}


/*void erasePlane (Point start, Color col){
	int posx = start.getX();
    int posy = start.getY();
    int nPoint = 58;
    int nColor = 3;
    
    int newX, newY;
    
    Point *arrPoint = new Point[58];
    Point *arrColor = new Point[3];
    
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
	
	//set point untuk Color
	//tail
	arrColor[0].setPoint(2,5);
	arrColor[1].setPoint(5,9);
	arrColor[2].setPoint(13,5);
	
	//scale
    int scaleFactor = 8;
    //1. pesawat
    for(int i = 0; i<nPoint; i++){
		newX = arrPoint[i].getX() * scaleFactor;
		newY = arrPoint[i].getY() * scaleFactor;
		arrPoint[i].setPoint(newX, newY);
	}
	//2. roda
	newX = p.getX() * scaleFactor;
	newY = p.getY() * scaleFactor;
	p.setPoint(newX, newY);
	
	//3. color
	for(int i = 0; i<nColor; i++){
		newX = arrColor[i].getX() * scaleFactor;
		newY = arrColor[i].getY() * scaleFactor;
		arrColor[i].setPoint(newX,newY);
	}
	
	//position
	//1. pesawat
	for (int i = 0; i<nPoint; i++){
		newX = arrPoint[i].getX() + posx;
		newY = arrPoint[i].getY() + posy;		
		arrPoint[i].setPoint(newX,newY);
	}	
	//2. roda
	newX = p.getX() + posx;
	newY = p.getY() + posy;
	p.setPoint(newX, newY);
	
	//3. color
	for(int i = 0; i<nColor; i++){
		newX = arrColor[i].getX() + posx;
		newY = arrColor[i].getY() + posy;
		arrColor[i].setPoint(newX,newY);
	}
	
	//floodFill
	Color navy_erase(0,0,129);
	Color skyblue_erase(135,206,236);
	Color dodgerblue_erase(30,144,254);
	draw.floodFill4Seed(arrColor[0].getX(),arrColor[0].getY(),col, navy_erase);
	draw.floodFill4Seed(arrColor[1].getX(),arrColor[1].getY(),col,skyblue_erase);
	draw.floodFill4Seed(arrColor[2].getX(),arrColor[2].getY(),col, dodgerblue_erase);	
	//draw
    draw.drawPolyline(58,arrPoint, black);
	draw.drawCircle (8,p, black);
	draw.drawCircle (4,p, black);

}

void erasePlaneAtEdge (Point start, Color col){
	int posx = start.getX();
    int posy = start.getY();
    int nPoint = 58;
    int nColor = 3;
    
    int newX, newY;
    
    Point *arrPoint = new Point[58];
    Point *arrColor = new Point[3];
    
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
	
	//set point untuk Color
	//tail
	arrColor[0].setPoint(2,5);
	arrColor[1].setPoint(5,9);
	arrColor[2].setPoint(13,5);
	
	//scale
    int scaleFactor = 8;
    //1. pesawat
    for(int i = 0; i<nPoint; i++){
		newX = arrPoint[i].getX() * scaleFactor;
		newY = arrPoint[i].getY() * scaleFactor;
		arrPoint[i].setPoint(newX, newY);
	}
	//2. roda
	newX = p.getX() * scaleFactor;
	newY = p.getY() * scaleFactor;
	p.setPoint(newX, newY);
	
	//3. color
	for(int i = 0; i<nColor; i++){
		newX = arrColor[i].getX() * scaleFactor;
		newY = arrColor[i].getY() * scaleFactor;
		arrColor[i].setPoint(newX,newY);
	}
	
	//position
	//1. pesawat
	for (int i = 0; i<nPoint; i++){
		newX = arrPoint[i].getX() + posx;
		newY = arrPoint[i].getY() + posy;		
		arrPoint[i].setPoint(newX,newY);
	}	
	//2. roda
	newX = p.getX() + posx;
	newY = p.getY() + posy;
	p.setPoint(newX, newY);
	
	//3. color
	for(int i = 0; i<nColor; i++){
		newX = arrColor[i].getX() + posx;
		newY = arrColor[i].getY() + posy;
		arrColor[i].setPoint(newX,newY);
	}
	
	//floodFill
	Color navy_erase(0,0,129);
	Color skyblue_erase(135,206,236);
	Color dodgerblue_erase(30,144,254);
	draw.floodFill4Seed(arrColor[0].getX(),arrColor[0].getY(),col, black);
	draw.floodFill4Seed(arrColor[1].getX(),arrColor[1].getY(),col, black);
	draw.floodFill4Seed(arrColor[2].getX(),arrColor[2].getY(),col, black);	
	//draw
    draw.drawPolyline(58,arrPoint, black);
	draw.drawCircle (8,p, black);
	draw.drawCircle (4,p, black);

}*/