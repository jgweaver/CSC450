//============================================================================
// Name        : CSC450_CT_Module5.cpp
// Author      : Weaver, Jonathan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
// Declaration for using std namespace
using namespace std;
// Reverses text in file and adds to the reverse file
void fileReversal() {
	// Opening the files to be read from with ifstream and to write to with ofstream
	ifstream iFile("resources/CSC450_CT5_mod5.txt");
	ofstream oFile("resources/CSC450_CT5_mod5_reverse.txt");
	// Checking that they opened
	if (!iFile.is_open()) {
		cerr << "Failed to open input file!" << endl;
		return;
	}

	if (!oFile.is_open()) {
			cerr << "Failed to open output file!" << endl;
			return;
	}

	string text, line;
	// Loop to add the lines from the file and store in 'text' variable
	while (getline(iFile, line)) {
		text += line + '\n';
	}
	// Reverse the text
	reverse(text.begin(), text.end());

	oFile << text;

	cout << "Reversed content written to CSS450_CT5_mod5_reverse.txt" << endl;

	iFile.close();
	oFile.close();
}
// Main function
int main() {
	string userInput;
	// Putting a bounds of 1000 characters for added security
	while(true) {
		cout << "Enter line!" << endl;
		getline(cin, userInput);

		if (userInput.length() > 1000) {
			cerr << "Input too Long, try again!" << endl;
		}
		else {
			break;
		}
	}
	// Opening file to append
	ofstream modFile("resources/CSC450_CT5_mod5.txt", ios::app);

	if (modFile.is_open()) {
		modFile << userInput << '\n';
		modFile.close();
		cout << "User input added a line to the mod5 file." << endl;
	}
	else {
		cerr << "Failed to open file!" << endl;
	}

	fileReversal();

	return 0;
}
