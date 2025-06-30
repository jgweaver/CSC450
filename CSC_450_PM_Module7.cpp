//============================================================================
// Name        : CSC_450_PM_Module7.cpp
// Author      : Weaver, Jonathan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

void countUp() {
	cout << "Count Up" << endl;
    for (int i = 0; i <= 20; ++i) {
        cout << i << endl;
        // Sleep for 1 second to show that it counts up in realtime
        Sleep(1000);
    }
}

void countDown(thread &upThread) {
	// Wait for count-up to finish
	if (upThread.joinable()) {
        upThread.join();
    }
	cout << "Count Down" << endl;
    for (int i = 20; i >= 0; --i) {
        cout <<  i << endl;
        // Sleep for 1 second
        Sleep(1000);
    }
}

int main() {
    thread upThread(countUp);
    thread downThread(countDown, ref(upThread));
    // Wait for countdown to finish
    downThread.join();
    return 0;
}

