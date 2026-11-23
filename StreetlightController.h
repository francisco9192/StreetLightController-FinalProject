#ifndef STREETLIGHTCONTROLLER_H
#define STREETLIGHTCONTROLLER_H

// Shared sensor classes used by the team's functions.
class MotionSensor {
private:
    bool motionDetected = false;
public:
    void setMotionDetected(bool motion) { motionDetected = motion; }
    bool getMotionDetected() const { return motionDetected; }
    bool isMotionDetected() const { return motionDetected; }
};

class BrightnessSensor {
private:
    int brightnessPercent = 0;
    int nightIdleBrightness = 30;
public:
    void setBrightness(int percent) {
        if (percent >= 0 && percent <= 100) brightnessPercent = percent;
    }
    int getBrightness() const { return brightnessPercent; }
    void setNightIdleBrightness(int percent) {
        if (percent >= 0 && percent <= 100) nightIdleBrightness = percent;
    }
    int getNightIdleBrightness() const { return nightIdleBrightness; }
};

class LightSensor {
private:
    int ambientLightLevel = 0;
public:
    void setLightLevel(int level) {
        if (level >= 0 && level <= 100) ambientLightLevel = level;
    }
    int getLightLevel() const { return ambientLightLevel; }
};

class StreetlightController {
private:
    MotionSensor motion;
    BrightnessSensor brightness;
    LightSensor light;
    bool automaticMode = true;
public:
    // Simulation defaults: below 50 is night, and idle brightness is 30%.
    StreetlightController() { updateAutomaticBrightness(); }
    MotionSensor& getMotionSensor() { return motion; }
    BrightnessSensor& getBrightnessSensor() { return brightness; }
    LightSensor& getLightSensor() { return light; }
    const MotionSensor& getMotionSensor() const { return motion; }
    const BrightnessSensor& getBrightnessSensor() const { return brightness; }
    const LightSensor& getLightSensor() const { return light; }
    void setAutomaticMode(bool automatic) { automaticMode = automatic; }
    bool isAutomaticMode() const { return automaticMode; }

    void updateAutomaticBrightness() {
        // Keep the user's brightness while manual mode is selected.
        if (!automaticMode) return;
        if (light.getLightLevel() >= 50)
            brightness.setBrightness(0);
        else if (motion.isMotionDetected())
            brightness.setBrightness(100);
        else
            brightness.setBrightness(brightness.getNightIdleBrightness());
    }
};

void motionSensor(StreetlightController& controller);
void activateMotionLight(StreetlightController& controller);
void displayStatus(const StreetlightController& controller);

#endif
