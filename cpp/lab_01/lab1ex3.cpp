#include <iostream>
using namespace std;

int main() {
	cout << "Difficulty Levels:\n";
	/* error... */
	cout << "1 - Easy\n"
	cout << "2 - Normal\n";
	cout << "3 - Hard\n";
	int choice;
	cout << "Choice: ";
	cin >> choice;
	switch(choice) {
		case 1:
			/* error... */
			cout < "You picked Easy.\n";
			break;
		case 2:
			cout << "You picked Normal.\n";
			/* error... */
			/* break; */
		case 3:
			cout << "You picked Hard.\n";
			break;
		default:
			cout << "You made an illegal choice.\n";
	}
	return 0;
}
