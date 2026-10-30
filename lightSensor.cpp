#include <iostream>

// Simulated hardware (replace with your real sensor and output pin)
float simulatedLux = 0.0f;

// Detects ambient light and returns it in lux
float lightSensor() {
    // Replace with a real read, e.g.:
    //   return analogRead(A0) * LUX_PER_COUNT;   // LDR on ADC (needs calibration)
    //   return lightMeter.readLightLevel();      // BH1750, already in lux
    return simulatedLux;
}
