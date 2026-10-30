#include <iostream>

// Simulated hardware (replace with your real sensor and output pin)
bool  lampOn       = false;

// Manually turns the streetlight on (true) or off (false)
void manualOverride(bool on) {
    lampOn = on;  // replace with digitalWrite(LAMP_PIN, on ? HIGH : LOW)
    std::cout << "Lamp " << (on ? "ON" : "OFF") << "\n";
}