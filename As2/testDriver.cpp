#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Parallelogram.h"
#include "Rhombus.h"
#include "Trapezoid.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

void testPolygon(){
	//area function in polygon is a virtual
	int i= 5;
	Polygon* p = new Polygon(i);
	p->setPoint(0,7,1);
	p->setPoint(1,8,5);
	p->setPoint(2,5,4);
	p->setPoint(3,2,5);
	p->setPoint(4,1,1);
	cout << "--- Polygon ---" << endl;
	cout << "Area: " << p->area() << endl;
	delete p;
}

void testQuadrilateral(){
	Quadrilateral* q = new Quadrilateral();
	q->setPoint(0,1,1);
	q->setPoint(1,5,1);
	q->setPoint(2,6,4);
	q->setPoint(3,2,4);
	cout << "\n--- Quadrilateral ---" << endl;
	cout<< "Area: " << q->area() << endl;
}

void testTrapezoid(){
	Trapezoid t(2,4);
	t.setPoint(0,1,1);
	t.setPoint(1,5,1);
	t.setPoint(2,4,3);
	t.setPoint(3,2,3);
	cout<< "\n--- Trapezoid ---" << endl;
	cout << "Shorter Side: " << t.getShorterSide() << endl;
	cout << "Longer Side: " << t.getLongerSide() << endl;
	cout << "Area: " << t.area() << endl;
}
void testParallelogram(){
	Parallelogram p(2.82,4,45);
	cout << "\n-------- Parallelogram ---------" << endl;
	cout << "Shorter Side: " << p.getShorterSide() << endl;
	cout << "Longer Side: " << p.getLongerSide() << endl;
	cout << "Acute Angle in Radian: " << p.getAcuteAngleInRadian() << endl;
	cout << "Area: " << setprecision(2) << p.area() << endl;
}
void testRhombus(){
	Rhombus r(1.8,67);
	cout << "\n-------- Rhombus --------" << endl;
	cout << "Side: " << r.getSide() << endl;
	cout << "Acute Angle in Radian: " << r.getRAngleInRadian() << endl;
	cout << "Area: " << setprecision(2) << r.area() << endl;
}
void testRectangle(){
	Rectangle rec(5,3);
	cout << "\n--- Rectangle ---" << endl;
	cout << "Width: " << rec.getLongerSide() << endl;
	cout << "Height: " << rec.getShorterSide() << endl;
	cout << "Area: " << rec.area() << endl;
}

void testSquare(){
	Square s(3);
	cout <<"\n--- Square ---" << endl;
	cout << "Side: " << s.getSide() << endl;
	cout << "Area: " << s.area() << endl;
}

int main(){

	testPolygon();
	testQuadrilateral();
	testTrapezoid();
	testParallelogram();
	testRhombus();
	testRectangle();
	testSquare();
	return 0;
}
