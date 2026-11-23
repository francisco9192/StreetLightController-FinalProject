
# Smart Streetlight Controller

This is our EECE 2140 final project. Our goal is to create a Smart Streetlight Controller using C++ that automatically adjusts the brightness of a streetlight based on surrounding light levels and motion detection.

## Features

1. Read and simulate motion input
2. Evaluate motion-based activation
3. Set manual brightness
4. Configure automatic nighttime brightness
5. Read and simulate surrounding light levels
6. Resume automatic day/night control
7. Manual on/off override
8. Display controller status

## Programming Language and Tools

We are using C++ to develop our program, Visual Studio Code to write and test the code, and GitHub to store and share our files.

## How to Compile and Run

1. Download the repository as a ZIP file and extract it.
2. Open the project folder in Visual Studio Code.
3. Open the terminal.
4. Compile the program using:

```powershell
g++ -std=c++17 main.cpp motionSensor.cpp activateMotionLight.cpp setManualBrightness.cpp setNightBrightness.cpp lightSensor.cpp runAutomaticMode.cpp manualOverride.cpp displayStatus.cpp -o streetlight.exe
```

5. Run the program using:

```powershell
.\streetlight.exe
```

6. Select an option from the menu. Enter 0 to exit the program.

## Documentation

Our Iteration 3 report and updated Excel project plan are located in the docs folder.

## Team Members

- Francisco Tovar
- Kenji Matsumoto
- Oluwadamilare Mustapha
