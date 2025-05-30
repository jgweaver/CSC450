//============================================================================
// Name        : CSC450_CT_Module2.cpp
// Author      : Weaver, Jonathan
// Version     :
// Copyright   : Your copyright notice
// Description : Takes two string inputs from user, Concatenates them then outputs the result
//============================================================================

#include <iostream>
#include <string>

using namespace std;
//Main function
int main() {

	//String variables for the first, second, and concatenated string
	string fString;
	string sString;
	string cString;

	//Loop to get the first and second string three times and prints the concatenated one
	for (int i = 0; i < 3; ++i) {

		cout << "Input count: " << i + 1 << endl;

		cout << "Enter first string: ";
		//To allow spaces for more variety of string length
		getline(cin, fString);

		cout <<"Enter second string: ";
		getline(cin, sString);

		//Concatenates the two strings into one
		cString = fString + sString;
		//Outputs the results
		cout << "Concatenated string results: " << cString << "\n\n";
	}

	return 0;
}
