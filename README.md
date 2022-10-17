
# Pill Reminder for Elderly using Arduino

This repository was made to document the process of implementing a Pill Reminder for Elderly using a Micro-controller and other hardware components for the project as a part of my Microprocessors and Interfacing course.  


## Table of Contents
- [About the Application](#about-the-application)
- [Components Used](#components-used)
- [Screenshots](#screenshots)
- [Hardware Setup](#hardware-setup)
- [Future Work](#future-work)
- [License](#license)

## About the Application

Pill Reminder for Elderly using Arduino reduces human effort by automating the process of reminding elderly to take their medicines at regular intervals of time.

This Arduino-based project has a wide range of applications and can be utilised by bedridden patients at home, physicians at hospitals, etc.

_This project features the following features:-_

- Displaying Information like time on a Screen
- Buzzer that rings at set intervals
- LED light that lights up at set intervals
- Buttons to set number of alarms in a given day ranging from 1 to 3 alarms a day

The simulation has been done on Tinkercad, the link to which can be found [here](https://www.tinkercad.com/things/0bJ8tCCZUKa-review2/editel)

## Components Used

_The components used in Tinkercad are as follows:-_

| S.no. | Component Name   | Image                                                                                                        |
|-------|------------------|--------------------------------------------------------------------------------------------------------------|
| 1     | Arduino Uno R3   | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/arduinoUno.png) |
| 2     | LCD 16 x 2 (I2C) | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/lcdI2C.png)     |
| 3     | Piezo            | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/buzzer.png)     |
| 4     | Breadboard       | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/breadboard.png) |
| 5     | LED              | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/led.png)        |
| 6     | Pushbuttons      | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/pushButton.png) |
| 7     | Resistors (1 kΩ) | ![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/resistor.png)   |


## Screenshots

_The below image shows the circuit diagram and the connections made._

![image](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/assets/diagram.png)

## Hardware Setup

_The following steps can be followed to implement this project using the hardware components:-_
1. Make the connections as per the circuit diagram. Account for digital pin numbers and make changes in the code if changed.  Change LCD size configuration based on the hardware component used.
2. Install Arduino IDE from [here](https://www.arduino.cc/en/software)
3. Create a sketch on Arduino IDE and add the code used.
4. Plug the Arduino to your laptop and upload the sketch to it.
5. Power the Arduino and the hardware should be implemented properly if all steps were followed until now.

## Future Work

_The following areas could be improved upon in the future:-_
- The project could make use of an RTC (Real-time clock) module for accurate time readings.
- Additionally, a feature to set alarms at user-defined time could also be added.

## License

This project is licensed under [MIT](https://github.com/NotHari/Pill-Reminder-for-Elderly-using-Arduino/blob/main/LICENSE).

<p align="center">Made with ❤ by Harikrishnan Nair</p>
