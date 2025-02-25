#include "Parallelogram.h"
#include <cmath>

#ifndef RHOMBUS_H_
#define RHOMBUS_H_

class Rhombus : public Parallelogram{
public:
	//constructor
	Rhombus(double s, double aa): Parallelogram(s,s,aa){}

	//getter
	double getSide() { return getShorterSide(); } /*return the side length */
	double getRAngleInRadian() {return getAcuteAngleInRadian();}/*return one angle value*/

	double area() const override{
		return Parallelogram::area();
	}
};



#endif /* RHOMBUS_H_ */
