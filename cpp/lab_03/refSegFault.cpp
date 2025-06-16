#include <iostream>

using namespace std;

/* func. prototype */
// int &getRefVar();

/* it does not work since we are returning an alias (i.e., a reference) to an object
	whose lifetime is limited to the scope of the function call */
// int &getRefVar() { /* https://stackoverflow.com/questions/4643713/returning-a-reference-to-a-local-variable-in-c */
	// int val = 32;
	// return val;
// }

/* this is the main func. */
int main(int argc, char *argv[]) {
	/* --- question 1 --- */
	/* define the var. ptr as a pointer to an int data type; initialize it as a null pointer */
	int *ptr = nullptr;
	/* initialize the var. ref as a reference to the dereferenced value of the var. ptr, which is technically a null pointer */
	int &ref = *ptr; /* this line of code will cause a segmentation fault since we are attempting to dereference a null pointer */
	cout << ref << endl;
	/* --- question 1 --- */

	/* --- question 2 --- */
	// cout << getRefVar() << endl;
	/* --- question 2 --- */

	return 0;
}
