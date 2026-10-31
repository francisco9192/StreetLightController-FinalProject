#include "StreetlightController.h"
#include <iostream>
#include <limits>

static bool readPercentage(const char* prompt, int& result) {
    std::cout << prompt;
    if (!(std::cin >> result)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a whole number from 0 to 100.\n";
        return false;
    }
    if (result < 0 || result > 100) {
        std::cout << "Brightness must be between 0 and 100.\n";
        return false;
    }
    return true;
}

void setNightBrightness(StreetlightController& controller) {
    int percent;
    if (!readPercentage("Enter idle nighttime brightness (0-100): ", percent)) return;
    controller.getBrightnessSensor().setNightIdleBrightness(percent);
    if (controller.isAutomaticMode()) controller.updateAutomaticBrightness();
    std::cout << "Nighttime idle brightness set to " << percent << "%.\n";
}

