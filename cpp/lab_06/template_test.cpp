#include "LinkedList.h"

#include <iostream>
using namespace std;

int main() {
	cout << "lab 6 test" << endl;
	cout << endl;

	LinkedList<int> lstInt; // rep. the ll of ints.
	LinkedList<string> lstStr; // rep. the ll of strings.

	// note: i did not perform any integration testing.

	// testing add() with ints.
	// ---
	cout << "before adding 1, 2, 3 to lstInt: ";
	lstInt.printList();
	cout << endl;
	lstInt.add(1);
	lstInt.add(2);
	lstInt.add(3);

	cout << "after adding 1, 2, 3 to lstInt: ";
	lstInt.printList();
	cout << endl;
	cout << endl;
	// ---

	// testing add() with strings.
	// ---
	cout << "before adding \"Hello\", \"World\", \"!\" to lstStr: ";
	lstStr.printList();
	cout << endl;
	lstStr.add("Hello");
	lstStr.add("World");
	lstStr.add("!");

	cout << "after adding \"Hello\", \"World\", \"!\" to lstStr: ";
	lstStr.printList();
	cout << endl;
	cout << endl;
	// ---

	// testing insertAt() with ints.
	// ---
	cout << "before inserting 0 at index 0 in lstInt: ";
	lstInt.printList();
	cout << endl;
	lstInt.insertAt(0, 0);

	cout << "after inserting 0 at index 0 in lstInt: ";
	lstInt.printList();
	cout << endl;
	cout << endl;
	// ---

	// testing insertAt() with strings.
	// ---
	cout << "before inserting \"abc\" at index 1 in lstStr: ";
	lstStr.printList();
	cout << endl;
	lstStr.insertAt(1, "abc");

	cout << "after inserting \"abc\" at index 1 in lstStr: ";
	lstStr.printList();
	cout << endl;
	cout << endl;
	// ---

	// testing findVal() with ints.
	lstInt.printList();
	cout << endl;
	cout << "findVal(0) in lstInt: ";
	if (lstInt.findVal(0)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	cout << "findVal(6) in lstInt: ";
	if (lstInt.findVal(6)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	cout << endl;
	// ---

	// testing findVal() with strings.
	lstStr.printList();
	cout << endl;
	cout << "findVal(abc) in lstStr: ";
	if (lstStr.findVal("abc")) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	cout << "findVal(racecar) in lstStr: ";
	if (lstStr.findVal("racecar")) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	cout << endl;
	// ---

	lstInt.insertAt(-3, 6);
	lstStr.insertAt(-3, "...");
	lstInt.insertAt(6, 6);
	lstStr.insertAt(6, "...");

	return 0;
}
