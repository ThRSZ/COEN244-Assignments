#ifndef POINT_H_
#define POINT_H_

class Point{
private:
	double x;
	double y;
public:
	//constructor
	Point(){
		x = 0;
		y = 0;
	}
	Point(double xc, double yc):x(xc),y(yc){}

	//getters
	double getX() const{ return x; }
	double getY() const{ return y; }

	//setters
	void setX(double sx){ x = sx; }
	void setY(double sy){ x = sy; }
};



#endif
