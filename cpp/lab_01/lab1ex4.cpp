#include <iostream>
using namespace std;

/* this is the main func. */
int main() {
	cout << "Welcome to our program!\n";
	float fahrenheit, celsius;
	cout << "Please enter the temperature in degrees Fahrenheit: ";
	cin >> fahrenheit;
	celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
	cout << "The temperature in degrees Celcius is: " << celsius;
	return 0;
}
