/*
 * upCountDownCount_Thread.cpp
 *
 *  Created on: Jun 29, 2025
 *      Author: jon
 */
#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        cout << "Count Up: " << i << endl;
        sleep(1000); // Sleep for 1 second (whole seconds only)
    }
}

void countDown(std::thread &upThread) {
    if (upThread.joinable()) {
        upThread.join(); // Wait for count-up to finish
    }

    for (int i = 20; i >= 0; --i) {
        cout << "Count Down: " << i << endl;
        sleep(1); // Sleep for 1 second
    }
}

int main() {
    thread upThread(countUp);
    thread downThread(countDown, ref(upThread));

    downThread.join(); // Wait for countdown to finish
    return 0;
}



