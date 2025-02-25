#include "Parallelogram.h"
#include <cmath>

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle : public Parallelogram{
public:
	//constructor
	Rectangle(double width, double height):
		Parallelogram(height, width, 90){
		//M_PI/2 equals to pi/2 which is 90 degrees for rectangle
	}

	//calculate area reuse area function
	double area() const override{
		return Parallelogram::area();
	}
};



#endif /* RECTANGLE_H_ */
