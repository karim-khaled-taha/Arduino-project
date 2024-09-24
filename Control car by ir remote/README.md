# Controlled Car by IR Remote System

This project uses an Arduino, an IR remote, to control a motor, horn, and several LEDs. The system can toggle the Car and horn with an IR remote.

## Components Used
- Arduino
- **IRremote Library** (for decoding IR remote signals)
- DC Motor
- Horn/Buzzer
- 4 Yellow LEDs
- IR Receiver


## Features
- **IR Control**: The motor and horn are controlled using the IR remote. Specific buttons on the remote control turning these components on and off.
- **LED Blinking Pattern**: When toggled, the four LEDs and the horn blink together in a 0.5-second interval.
  
## How It Works
1. The IR receiver detects signals from an IR remote.
2. Based on the received signal, the motor or horn is turned on/off.
4. An additional feature allows for a blinking pattern of the LEDs and horn when triggered by a specific IR signal.

# Demo Video
https://github.com/user-attachments/assets/b957b8ec-3ab9-462b-9d5d-e5ced90a470b



