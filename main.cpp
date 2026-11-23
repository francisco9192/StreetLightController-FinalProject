
#include <iostream>
#include <limits>
#include "StreetlightController.h"
using namespace std;

void setManualBrightness(StreetlightController& controller);
void setNightBrightness(StreetlightController& controller);
void runAutomaticMode(StreetlightController& controller);



void readLightLevel() {
    cout << "Not implemented yet.\n";
}

void manualOverride() {
    cout << "Not implemented yet.\n";
}


int main() {
    StreetlightController controller;
    int choice = -1;

    do {
        cout << "\n===== SMART STREETLIGHT CONTROLLER =====\n";
        cout << "1. Read / simulate motion input\n";
        cout << "2. Evaluate motion-based activation\n";
        cout << "3. Set manual brightness\n";
        cout << "4. Configure automatic night idle brightness\n";
        cout << "5. Read / simulate ambient light\n";
        cout << "6. Resume automatic day/night control\n";
        cout << "7. Manual on/off override\n";
        cout << "8. Display controller status\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from 0 to 8.\n";
            continue;
        }

        switch (choice) {
            case 1:
                motionSensor(controller);
                break;

            case 2:
                activateMotionLight(controller);
                break;

            case 3:
                setManualBrightness(controller);
                break;

            case 4:
                setNightBrightness(controller);
                break;

            case 5:
                readLightLevel();
                break;

            case 6:
                runAutomaticMode(controller);
                break;

            case 7:
                manualOverride();
                break;

            case 8:
                displayStatus(controller);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}
