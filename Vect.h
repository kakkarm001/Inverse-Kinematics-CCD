#pragma once

#ifndef VECT_GUARD
#define VECT_GUARD


class Vect {
private:

public:
	double x;
	double y;
	double z;

	Vect();
	Vect(double, double, double);

	double getX();
	double getY();
	double getZ();
	double length();
	bool equals(Vect other);

	Vect normalized();
	Vect neg();
	double dot(Vect other);
	double angle(Vect other);
	Vect cross(Vect other);

	Vect operator + (const Vect &other);
	Vect operator - (const Vect &other);
	Vect operator * (const Vect &other);
	Vect operator / (const Vect &other);
};

#endif
