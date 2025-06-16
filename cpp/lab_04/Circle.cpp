#include <iostream> // include necessary header for input/output stream
#include <cmath> // include necessary header for mathematical functions
#include "Circle.h"

using namespace std;

const double PI = 3.14159; // define the value of PI as a constant

/*
now follows each of the method implementations. the <class>:: that
preces each method identifies that the function belongs to the class
*/

// default constructor
Circle::Circle() {
	x_coord = 0;
	y_coord = 0;
	radius = 5.0;
}

// constructor to create a new circle with the given values
Circle::Circle(int x_val, int y_val, double r_val) {
	x_coord = x_val;
	y_coord = y_val;
	if(r_val > 0.0) {
		radius = r_val;
	} else {
		cout << "error: the radius cannot be negative!" << endl;
		radius = 5.0;
	}
}

// setters that change the values of the attributes
void Circle::setX(int x_val) {
	x_coord = x_val;
}

void Circle::setY(int y_val) {
	y_coord = y_val;
}

void Circle::setRadius(double r_val) {
	if(r_val > 0.0) {
		radius = r_val;
	} else {
		cout << "error: the radius cannot be negative!" << endl;
		radius = r_val;
	}
}

// getters that return information about the circle
int Circle::getX() const {
	return x_coord;
}

int Circle::getY() const {
	return y_coord;
}

double Circle::getRadius() const {
	return radius;
}

// translates the circle along x and y values
void Circle::translate(int horizShift, int vertShift) {
	x_coord = x_coord + horizShift;
	y_coord = y_coord + vertShift;
}

// returns the circle's area
double Circle::getArea() const {
	return PI * pow(radius, 2);
}

// displays the circle's attributes like this: "Radius: 5.0 at point x = 0, y = 0"
void Circle::displayCircle() const {
	cout << "Radius: " << getRadius() << " at point x = " << getX() << ", y = " << getY() << endl;
}

// returns true if c intersects the calling circle
bool Circle::intersect(const Circle &c) const {
	// reference: https://cplusplus.com/forum/general/35377/
	return (radius + c.radius) >= sqrt(pow(x_coord - c.x_coord, 2) + pow(y_coord - c.y_coord, 2));
}

// compares two circles and returns true if both circles have same radius and x, y coordinate else returns false.
bool Circle::operator==(const Circle &c) const {
	return radius == c.radius && x_coord == c.x_coord && y_coord == c.y_coord;
}

// returns a new circle with radius as sum of radius of c1 and c2. Compare the abolute magnitude of the coordinates of both the circles and set the x and y values with the greater value.
Circle Circle::operator+(const Circle &c) const {
	double r_val = radius + c.radius;
	int x_val = 0;
	int y_val = 0;

	if(abs(x_coord) < abs(c.x_coord)) {
		x_val = c.x_coord;
	} else {
		x_val = x_coord;
	}

	if(abs(y_coord) < abs(c.y_coord)) {
		y_val = c.y_coord;
	} else {
		y_val = y_coord;
	}

	return Circle(x_val, y_val, r_val);
}
