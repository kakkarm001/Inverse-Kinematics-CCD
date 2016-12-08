	
#include "Vect.h"
#include <math.h>

	Vect::Vect() {
		x = 0;
		y = 0;
		z = 0;
	}

	Vect::Vect(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}


	double Vect::getX() { return x; }
	double Vect::getY() { return y; }
	double Vect::getZ() { return z; }

	double Vect::length() {
		return sqrt((x * x) + (y * y) + (z * z));
	}

	Vect Vect::normalized() {
		double mag = length();

		return Vect(x / mag, y / mag, z / mag);
	}

	Vect Vect::neg() {
		return Vect(-x, -y, -z);
	}

	double Vect::dot(Vect other) {
		return x * other.getX() + y * other.getY() + z * other.getZ();
	}

	double Vect::angle(Vect other) {
		double dot = this->dot(other);
		/* need to doublecheck if angle calculation is right*/
		double otherLength = other.length();
		double thisLength = length();
		double angle = acos(dot/(otherLength+thisLength));
			return angle;
	}

	Vect Vect::cross(Vect other) {
		double x_ = y * other.getZ() - z * other.getY();
		double y_ = z * other.getX() - x * other.getZ();
		double z_ = x * other.getY() - y * other.getX();

		return Vect(x_, y_, z_);
	}

	Vect Vect::operator + (const Vect &other) {
		return Vect(x + other.x, y + other.y, z + other.z);
	}

	Vect Vect::operator - (const Vect &other) {
		return Vect(x - other.x, y - other.y, z - other.z);
	}

	Vect Vect::operator * (const Vect &other) {
		return Vect(x * other.x, y * other.y, z * other.z);
	}

	Vect Vect::operator / (const Vect &other) {
		return Vect(x / other.x, y / other.y, z / other.z);
	}

	bool Vect::equals(Vect other) { //doublecheck if works
		if(other.x == x && other.y == y && other.z == z){
			return true;
		} 

		return false;
	}

