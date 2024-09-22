# Incubator Control System

This project is a simulation of an incubator system using Arduino. The system controls the temperature, displays key parameters on an LCD, and handles user input for adjusting the temperature. It also includes error detection using an LDR sensor and provides feedback using an LED and a buzzer.

## Table of Contents

- [Overview](#overview)
- [Components](#components)
- [Features](#features)
- [Circuit Design](#circuit-design)

## Overview

The incubator control system uses sensors and actuators to monitor and adjust the temperature inside the incubator. The system features buttons for increasing and decreasing the desired temperature, setting the temperature, and starting or stopping the system. It includes safety mechanisms that trigger a buzzer and LED if the door (simulated by an LDR sensor) is detected as open.

## Components

- **Arduino Uno**
- **16x2 LCD Display**
- **Push Buttons (Increase, Decrease, Set, Start/End)**
- **Buzzer (Error Indicator)**
- **LED (Error Indicator)**
- **Fan (Simulated with an output pin)**
- **Heater (Simulated with an LED)**
- **NPN Transistor (To control the fan)**
- **LDR (Light Dependent Resistor to detect door open)**
- **Thermistor or temperature sensor (Simulated with an analog input)**

## Features

- **Temperature Monitoring**: The system reads temperature values and adjusts the fan or heater accordingly.
- **User Input**: Allows the user to set the desired temperature using buttons.
- **LCD Display**: Shows the current temperature and the user-set temperature.
- **Error Detection**: If the door is open (detected by the LDR), an error message is displayed, and the buzzer and LED are activated.
- **Fan and Heater Control**: Automatically controls the fan and heater based on the temperature difference.

## Circuit Design

Below is an overview of the circuit components connected to the Arduino.

1. **LCD**: Connected to digital pins 2, 3, 4, 5, 11, and 12.
2. **Buttons**: Four buttons for "Increase", "Decrease", "Set", and "Start/End" connected to digital pins 7, 9, 10, and 8 respectively.
3. **Buzzer**: Connected to pin A2 for error indication.
4. **LED Error Indicator**: Connected to pin A1 for error signaling.
5. **Fan**: Simulated using a PWM pin (pin 6) for speed control.
6. **Heater**: Simulated using pin 13.
7. **LDR Sensor**: Connected to pin A5 to detect if the door is open.

### Schematic
![Screenshot 2023-05-26 180025](https://github.com/user-attachments/assets/4d171c77-bf29-4ed6-9a00-ae15c7415747)

![IMG_1495 - Copy1](https://github.com/user-attachments/assets/aa65cd60-60bc-4c2f-826b-92bc856fbe7a)


### Main Logic

- The temperature is continuously read, and if the door is open, an error is displayed.
- The buttons control the temperature settings, and the fan or heater is turned on based on the current and desired temperature.
- The LCD provides feedback to the user, showing both the actual and desired temperatures.


