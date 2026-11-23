#include <iostream>
#include <limits>
#include "StreetlightController.h"
using namespace std;

void setManualBrightness(StreetlightController& controller);
void setNightBrightness(StreetlightController& controller);
void runAutomaticMode(StreetlightController& controller);

float lightSensor();
extern float simulatedLux;
void manualOverride(bool on);

void readLightLevel(StreetlightController& controller) {
    int level;

    cout << "Enter simulated light level (0 = dark, 100 = bright): ";

    if (!(cin >> level)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a whole number from 0 to 100.\n";
        return;
    }

    if (level < 0 || level > 100) {
        cout << "Light level must be between 0 and 100.\n";
        return;
    }

    simulatedLux = level;

    controller.getLightSensor().setLightLevel(
        static_cast<int>(lightSensor())
    );

    controller.updateAutomaticBrightness();

    cout << "Simulated light level: "
         << controller.getLightSensor().getLightLevel()
         << "/100\n";

    cout << "Streetlight brightness: "
         << controller.getBrightnessSensor().getBrightness()
         << "%\n";
}

void setManualOverride(StreetlightController& controller) {
    int setting;

    cout << "Enter 1 to turn the streetlight ON or 0 to turn it OFF: ";

    if (!(cin >> setting)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter 0 or 1.\n";
        return;
    }

    if (setting != 0 && setting != 1) {
        cout << "Please enter 0 or 1.\n";
        return;
    }

    manualOverride(setting == 1);

    controller.setAutomaticMode(false);

    if (setting == 1) {
        controller.getBrightnessSensor().setBrightness(100);
    } else {
        controller.getBrightnessSensor().setBrightness(0);
    }

    cout << "Manual mode is active. Choose option 6 to resume automatic control.\n";
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

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from 0 to 8.\n";
            choice = -1;
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
                readLightLevel(controller);
                break;

            case 6:
                runAutomaticMode(controller);
                break;

            case 7:
                setManualOverride(controller);
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
