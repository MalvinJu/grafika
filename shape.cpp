#include "shape.h"

#define PI  3.14159265
#define EPS 0.00001
using namespace std;

//Below is used to determine wether a point is inside a polyon
//Code from Competitive Programming 3 chapter 7
struct vec{
	double x,y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(Point a, Point b){
	return vec(b.getX() - a.getX(), b.getY() - a.getY());
}

double dot(vec a, vec b){
	return a.x * b.x + a.y * b.y;
}

double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}

double angle(Point A, Point O, Point B){
	vec oa = toVec(O,A), ob = toVec(O,B);
	return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b){
	return a.x * b.y - a.y * b.x;
}

bool ccw(Point P, Point Q, Point R){
	return cross(toVec(P,Q), toVec(P,R)) > 0;
}

bool is_inside_polygon(Point P, vector<Point> edges){
	//Code from Competitive programming 3 page 287
	
	double sum = 0;
	edges.push_back(edges[0]);
	for(int i=0; i < (int) edges.size()-1; i++){
		if (ccw(P, edges[i], edges[i+1]))
			sum+=angle(edges[i], P, edges[i+1]);
		else
			sum-=angle(edges[i], P, edges[i+1]);
	}
	return fabs( fabs(sum) - 2 * PI ) < EPS;

}


Point calculate_center(vector<Point> edge){
	long long sumX, sumY;
	for(int i=0; i<edge.size(); i++){
		sumX += edge[i].getX();
		sumY += edge[i].getY();
	}
	return Point(sumX/edge.size() , sumY/edge.size());
}

Point getFloodFillSeed(vector<Point> edge){
	int  MaxX = -1,MaxY=-1, MinX=1000000, MinY=1000000;
	for(int i=0; i<edge.size(); i++){
		MaxX = max(MaxX , edge[i].getX());
		MaxY = max(MaxY,edge[i].getY());
		MinX = min(MinX,edge[i].getX());
		MinY = min(MinY,edge[i].getY());
	}
	int x = rand() % (MaxX - MinX +1) + MinX ;
	int y = rand() % (MaxY - MinY +1) + MinY ;
	Point P(x,y);
	while(is_inside_polygon(P, edge) == false){
		x = rand() % (MaxX - MinX +1) + MinX ;
	 	y = rand() % (MaxY - MinY +1) + MinY ;

	 	P = Point(x,y);
	}
	return P;
}



Shape::Shape(vector<Point>& starting_edge, Color C ){


	edges.clear();
	edges = starting_edge;
	Border = C;

	center = calculate_center(starting_edge);
	floodfill_seed = getFloodFillSeed(edges);

	draw();
}

Shape::~Shape(){
	erase();
	edges.clear();
}

void Shape::moveBy(int deltaX, int deltaY){
	erase();
	for(int i=0; i<edges.size(); i++){
		edges[i].moveBy(deltaX, deltaY);
	}
	center.moveBy(deltaX, deltaY);
	floodfill_seed.moveBy(deltaX,deltaY);
	draw();
}



//rotate the object by theta degree clockwise
void Shape::Rotate(int theta){
	erase();
	for(int i=0; i<edges.size(); i++){
		edges[i].moveBy(-center.getX(), -center.getY());
		edges[i].rotate(theta);
		edges[i].moveBy(center.getX(), center.getY());

	}
	draw();
}


void Shape::erase(){
	linedrawer.drawPolygon(edges,Color(0,0,0) );
	//linedrawer.floodFill4Seed(floodfill_seed.getX(), floodfill_seed.getY(), Border, Color(0,0,0));
}
void Shape::draw(){
	linedrawer.drawPolygon(edges,Border);
	linedrawer.floodFill4Seed(floodfill_seed.getX(), floodfill_seed.getY(), Border, Fill);

}

//set floodfill color
void Shape::setFillColor(Color C){
	Fill = C;
}
//set Border Color to color c
void Shape::setBorderColor(Color c){
	Border = c;
}

void Shape::setCenter(Point P){
	center = P;
}

