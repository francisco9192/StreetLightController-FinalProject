// Francisco Tovar - T8: Show the current controller readings.
#include "StreetlightController.h"
#include <iostream>
using namespace std;

void displayStatus(const StreetlightController& controller) {
    int brightness = controller.getBrightnessSensor().getBrightness();
    cout << "\n----- CONTROLLER STATUS -----\n";
    cout << "Mode: " << (controller.isAutomaticMode() ? "Automatic" : "Manual") << "\n";
    cout << "Motion: "
         << (controller.getMotionSensor().isMotionDetected() ? "Detected" : "Not detected") << "\n";
    cout << "Ambient light: " << controller.getLightSensor().getLightLevel() << "/100\n";
    cout << "Brightness: " << brightness << "%\n";
    cout << "Streetlight: " << (brightness > 0 ? "ON" : "OFF") << "\n";
    cout << "Nighttime idle brightness: "
         << controller.getBrightnessSensor().getNightIdleBrightness() << "%\n";
}
