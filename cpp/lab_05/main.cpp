// main.cpp
// author: danny kan (kan.74@osu.edu)

#include "main.h"

void print(const Shape& s) {
	s.display();
}

// this is the main func.
int main(int argc, char *argv[]) {
	Circle c(10);
	Rectangle r(3, 4);
	// Quadrilateral q(2, 4); // Uncommenting this line should cause an error

	Trapezoid trap(3, 4, 5);

	print(c);
	print(r);
	print(trap);

	return 0;
}
