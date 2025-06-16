#include <iostream>
#include "Circle.h"

using namespace std;

int main(int argc, char *argv[]) {
	Circle c0;
	c0.displayCircle();

	Circle c1(3, 3, 10);
	c1.displayCircle();

	cout << c1.getX() << endl;
	cout << c1.getY() << endl;
	cout << c1.getRadius() << endl;
	cout << c1.getArea() << endl;

	c1.translate(-3, -6);
	c1.displayCircle();

	Circle c2(6, 9, 6);
	c2.displayCircle();

	if(c1.intersect(c2)) {
		cout << "itersect!" << endl;
	} else {
		cout << "do not intersect!" << endl;
	}

	Circle c3(6, 9, 10);
	if(c2 == c3) {
		cout << "equal!" << endl;
	} else {
		cout << "not equal!" << endl;
	}

	c3.setX(10);
	c3.setY(20);
	c3.setRadius(30);
	c3.displayCircle();

	return 0;
}
