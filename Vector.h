#pragma once

class Vect {
private:
	double x;
	double y;
	double z;

public:
	Vect();
	Vect(double, double, double);

	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }

	double length() {
		return sqrt((x * x) + (y * y) + (z * z));
	}

	Vect normalized() {
		double mag = length();

		return Vect(x / mag, y / mag, z / mag);
	}

	Vect neg() {
		return Vect(-x, -y, -z);
	}

	double dot(Vect other) {
		return x * other.getX() + y * other.getY() + z * other.getZ();
	}

	Vect cross(Vect other) {
		double x_ = y * other.getZ() - z * other.getY();
		double y_ = z * other.getX() - x * other.getZ();
		double z_ = x * other.getY() - y * other.getX();

		return Vect(x_, y_, z_);
	}

	Vect operator + (const Vect &other) {
		return Vect(x + other.x, y + other.y, z + other.z);
	}

	Vect operator - (const Vect &other) {
		return Vect(x - other.x, y - other.y, z - other.z);
	}

	Vect operator * (const Vect &other) {
		return Vect(x * other.x, y * other.y, z * other.z);
	}

	Vect operator / (const Vect &other) {
		return Vect(x / other.x, y / other.y, z / other.z);
	}
};

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