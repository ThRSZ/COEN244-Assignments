#include "Polygon.h"
#include <cmath>

#ifndef QUADRILATERAL_H_
#define QUADRILATERAL_H_

class Quadrilateral : public Polygon{
public:
	//constructor
	Quadrilateral():Polygon(4){
		//Quadrilateral has 4 points
	}

	//area function reused from ploygon
	virtual double area() const override{
		return Polygon::area();
	}
};


#endif /* QUADRILATERAL_H_ */
