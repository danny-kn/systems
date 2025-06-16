// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

// attributes
//		x coordinate (an int), can be negative
//		y coordinate (an int), can be negative
//		radius (a double), must be greater than 0.0

// methods
// 		a default constructor that creates a circle of radius 5 at position 0, 0 (completed)
//		a constructor with parameters for x, y, and radius (completed)
//		a copy constructor which copies one circle details to the other (n/a)
//		getters and setters for radius, x, and y coordinate. take care of invalid values for radius. (completed)
//		void translate(int horizShift, int vertShift) - translates the circle along x and y axis (completed)
//		double getArea() - returns the circle's area (completed)
//		void displayCircle() - displays the circle's attributes like this: "Radius: 5.0 at point x = 0, y = 0" (completed)
//		bool intersect(Circle c) - returns true if c intersects the calling circle (completed)
//		bool operator == (Circle c) - compares two circles and returns true if both circles have same radius and x, y coordinate else returns false. (completed)
//		Circle operator + (const Circle &c1, const Circle &c2) - returns a new circle with radius as sum of radius of c1 and c2. Compare the abolute maginutude of the coordinates of both the circles and set the x and y values with the greater value. (completed)

class Circle {
	public:
		// default constructor
		Circle(); // the default constructor

		// a copy constructor which copies one circle details to the other
		// ...

		// constructor with parameters
		Circle(int x_coord, int y_coord, double radius);

		// setters that change the values of the attributes
		void setX(int x_coord); // modifies the x coordinate
		void setY(int y_coord); // modifies the y coordinate
		void setRadius(double radius); // modifies the radius

		// getters that return information about the circle, note the const at the end of the method
		int getX() const; // obtains the x coordinate
		int getY() const; // obtains the y coordinate
		double getRadius() const; // obtains the radius

		// translates the circle along x and y values
		void translate(int horizShift, int verShift);

		// returns the circle's area
		double getArea() const;

		// displays the circle's attributes like this: "Radius: 5.0 at point x = 0, y = 0"
		void displayCircle() const;

		// returns true if c intersects the calling circle
		bool intersect(const Circle &c) const;

		// compares two circles and returns true if both circles have same radius and x, y coordinate else returns false.
		bool operator == (const Circle &c) const;

		// returns a new circle with radius as sum of radius of c1 and c2. Compare the abolute maginutude of the coordinates of both the circles and set the x and y values with the greater value.
		Circle operator + (const Circle &c) const;

	private:
		int x_coord;
		int y_coord;
		double radius;
};

#endif
