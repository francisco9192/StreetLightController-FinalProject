// Francisco Tovar - T1: Read simulated motion input.
#include "StreetlightController.h"
#include <iostream>
#include <limits>
using namespace std;

void motionSensor(StreetlightController& controller) {
    int motion;
    cout << "Enter motion (1 = detected, 0 = not detected): ";

    if (!(cin >> motion)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter 0 or 1.\n";
        return;
    }
    if (motion != 0 && motion != 1) {
        cout << "Please enter 0 or 1.\n";
        return;
    }

    // Save the reading so the other functions can use it.
    controller.getMotionSensor().setMotionDetected(motion == 1);
    cout << "Motion " << (motion == 1 ? "detected" : "not detected") << ".\n";
    cout << "Choose option 2 to evaluate the light.\n";
}
