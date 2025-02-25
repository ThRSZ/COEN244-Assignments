#include "Quadrilateral.h"

#ifndef TRAPEZOID_H_
#define TRAPEZOID_H_

class Trapezoid : public Quadrilateral{
private:
	double shorterSide;
	double longerSide;
public:
	//constructor
	Trapezoid(double ss, double ls): shorterSide(ss),longerSide(ls){}

	//getters
	double getShorterSide() const { return shorterSide; }
	double getLongerSide() const { return longerSide; }

	//calculate area
	double area() const override{
		//area = 1/2 (ls+ss) * height
		double a = 0.5 * (shorterSide + longerSide) * (points[2].getY() - points[0].getY());
		return a;
	}

};



#endif /* TRAPEZOID_H_ */
