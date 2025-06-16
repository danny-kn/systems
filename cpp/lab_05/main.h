#include <iostream> // include necessary header for input/output stream
#include <cmath> // include necessary header for mathematical functions

using namespace std;

const double PI = 3.14159; // define the value of PI as a constant

class Shape {
	public:
		virtual double area() const = 0;
		virtual void display() const = 0;
};

class Circle : public Shape {
	private:
		double radius;
	public:
		Circle(double r) : radius(r) {
			if(radius <= 0) {
				cout << "error: r <= 0" << endl;
				radius = 1.0;
			}
		}

		double area() const {
			return PI * radius * radius;
		}

		void display const s() {
			cout << "Circle: " << radius << " | Area = " << area() << endl;
		}
};
