#include "Quadrilateral.h"
#include <cmath>

#ifndef PARALLELOGRAM_H_
#define PARALLELOGRAM_H_

class Parallelogram : public Quadrilateral{
private:
	double shorterSide;
	double longerSide;
	double acuteAngle;

public:
	//constructor
	Parallelogram(double ss, double ls, double aa):
		shorterSide(ss), longerSide(ls),acuteAngle(aa * M_PI/180){}

	//getters
	double getShorterSide() const { return shorterSide; }
	double getLongerSide() const { return longerSide; }
	double getAcuteAngleInRadian() const { return acuteAngle; }

	//calculate area
	double area() const override{
		return shorterSide * longerSide * sin(acuteAngle);
	}
};



#endif /* PARALLELOGRAM_H_ */
