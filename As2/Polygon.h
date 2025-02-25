#include "Point.h"
#include <cmath>

#ifndef POLYGON_H_
#define POLYGON_H_

class Polygon{
protected:
	int size;
	Point* points;

public:
	//constructor
	Polygon(int sz):size(sz){
		points = new Point[sz];
	}

	//setters
	void setPoint(int index, const Point& p){
		//check if index is greater than or equal to 0
		if(index >= 0 && index < size){
			points[index] = p;
		}
	}
	void setPoint(int index, double x, double y){
		if(index >= 0 && index < size){
			points[index] = Point(x,y);
		}
	}

	//calculate area
	virtual double area() const{
		double sum = 0;
		for(int i = 0; i < size - 1; i++){
			sum += (points[i].getX() * points[i+1].getY() - points[i+1].getX() * points[i].getY());
		}
		sum += (points[size-1].getX() * points[0].getY() - points[0].getX() * points[size-1].getY());
		return 0.5 * fabs(sum);
	}

	//destructor and delete
	virtual ~Polygon(){
		delete[] points;
	}
};



#endif /* POLYGON_H_ */
