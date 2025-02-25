#include "Rectangle.h"

#ifndef SQUARE_H_
#define SQUARE_H_

class Square : public Rectangle{
public:
	//constructor
	Square(double s):Rectangle(s,s){}

	//getter
	double getSide(){ return getShorterSide(); }

	//reuse area function from
	double area() const override{
		return Rectangle::area();
	}
};



#endif /* SQUARE_H_ */
