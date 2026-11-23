
#include <iostream>
#include <limits>
#include "StreetlightController.h"
using namespace std;

void setManualBrightness(StreetlightController& controller);
void setNightBrightness(StreetlightController& controller);
void runAutomaticMode(StreetlightController& controller);

void readMotion() {
    cout << "Not implemented yet.\n";
}

void activateMotionLight() {
    cout << "Not implemented yet.\n";
}

void readLightLevel() {
    cout << "Not implemented yet.\n";
}

void manualOverride() {
    cout << "Not implemented yet.\n";
}

void displayStatus() {
    cout << "Not implemented yet.\n";
}

void testPicoLightSensor() {
    cout << "Not implemented yet.\n";
}

int main() {
    StreetlightController controller;
    int choice;

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
        cout << "9. Test light detection on Pico board\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from 0 to 9.\n";
            continue;
        }

        switch (choice) {
            case 1:
                readMotion();
                break;
            case 2:
                activateMotionLight();
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
                displayStatus();
                break;
            case 9:
                testPicoLightSensor();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 0);
class LightSensor {
    int readValue() {
        // Simulate reading a value from the light sensor
        return 42; // Placeholder value
    }
};
bool  lampOn       = false;

void manualOverride(bool on) {
    lampOn = on;  // replace with digitalWrite(LAMP_PIN, on ? HIGH : LOW)
    std::cout << "Lamp " << (on ? "ON" : "OFF") << "\n";
}
    return 0;
}
