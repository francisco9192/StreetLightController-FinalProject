// Francisco Tovar - T2: Update the light based on motion.
#include "StreetlightController.h"
#include <iostream>
using namespace std;

void activateMotionLight(StreetlightController& controller) {
    // Do not cancel a manual brightness setting.
    if (!controller.isAutomaticMode()) {
        cout << "Manual mode is active. Choose option 6 to resume automatic control.\n";
        return;
    }

    // At night, motion gives full brightness. Otherwise use the idle setting.
    controller.updateAutomaticBrightness();
    if (controller.getLightSensor().getLightLevel() >= 50)
        cout << "Daytime: the streetlight is off.\n";
    else if (controller.getMotionSensor().isMotionDetected())
        cout << "Motion detected: the streetlight is at full brightness.\n";
    else
        cout << "No motion: using nighttime idle brightness.\n";

    cout << "Streetlight brightness: "
         << controller.getBrightnessSensor().getBrightness() << "%\n";
}
