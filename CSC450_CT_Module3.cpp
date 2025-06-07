//============================================================================
// Name        : CSC450_CT_Module3.cpp
// Author      : Weaver, Jonathan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>
// Standard namespace declaration
using namespace std;
// Main function
int main() {
	int int1, int2, int3;

	while (true) {
		cout << "Enter three integers: ";
		cin >> int1 >> int2 >> int3;
		// Handles invalid entries of letters, symbols, or out of bounds numbers for int
		if (cin.fail()) {
			// Clears error flag
			cin.clear();
			// Discards the invalid input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			// Sends error message to user
			cerr << "\nLast input invalid. Try again! ";
			continue;
		} else {
			// Ends the loop when input is valid
			break;
		}
	}
	// Create pointers for ints
	int* ptr1 = new int(int1);
	int* ptr2 = new int(int2);
	int* ptr3 = new int(int3);

	//Display contents of variables and pointers
	cout << "\nValues entered: " << endl;
	cout << "int1 = " << int1 << ", ptr1 = " << ptr1 << endl;
	cout << "int2 = " << int2 << ", ptr2 = " << ptr2 << endl;
	cout << "int3 = " << int3 << ", ptr3 = " << ptr3 << endl;

	// Free the dynamically allocated memory
	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}
