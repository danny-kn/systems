// classes.cpp
// author: danny kan (kan.74@osu.edu)

#include <iostream>
using namespace std;

class A {
protected:
	int var;
public:
	A() { var = 0; }
	void increment() { var++; }
	virtual void decrement() { var--; }

	// void print() { cout << "var = " << var << endl; }
	virtual void print() { cout << "var = " << var << endl; }
};

class B : public A {
	protected:
		int varB; // add a protected variabled varB to B as requested...
	public:
		B() { varB = 0; } // add a constructor to B to initilize varB to 0 as requested...
		void increment() { var += 3; }
		virtual void decrement() { var -= 3; }

		// add a print() method in B so that both var and varB are printed...
		void print() { cout << "var = " << var << "; varB = " << varB << endl; }
		// virtual void print() { cout << "var = " << var << "; varB = " << varB << endl; }
};

A func(A x) { return x; }

// this is the main func.
int main(int argc, char *argv[]) {
 	A a;
 	A * ptr;
	ptr = &a; // pointer ptr is currently pointing to the memory address of object a of class A...
 	ptr -> increment();
 	ptr -> print();
 	ptr -> decrement();
 	ptr -> print();

 	B b; // add an object b of class B as requested...
 	ptr = &b; // set the pointer ptr to point to the memory address of object b of class B as requested...

 	ptr -> increment(); // call increment()
 	ptr -> print(); // call print()
 	ptr -> decrement(); // call decrement()
 	ptr -> print(); // call print()

	// A a;
	// B b;
	// A * ptr;
	// a = b;
	// a.print();
	// ptr = &a;
	// ptr -> print();

	// B b;
	// b.A::print();
	// func(b).print();

	return 0;
}
