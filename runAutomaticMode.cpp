#include "StreetlightController.h"
#include <iostream>

void runAutomaticMode(StreetlightController& controller) {
    controller.setAutomaticMode(true);
    controller.updateAutomaticBrightness();
    std::cout << "Automatic mode enabled.\n";
    std::cout << "Ambient light: " << controller.getLightSensor().getLightLevel() << "/100\n";
    std::cout << "Motion: " << (controller.getMotionSensor().isMotionDetected() ? "detected" : "not detected") << "\n";
    std::cout << "Streetlight brightness: " << controller.getBrightnessSensor().getBrightness() << "%\n";
}
