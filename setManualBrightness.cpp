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

void setManualBrightness(StreetlightController& controller) {
    int percent;
    if (!readPercentage("Enter brightness (0-100): ", percent)) return;
    controller.setAutomaticMode(false);
    controller.getBrightnessSensor().setBrightness(percent);
    std::cout << "Manual brightness set to " << percent << "%. Automatic mode is paused.\n";
}

