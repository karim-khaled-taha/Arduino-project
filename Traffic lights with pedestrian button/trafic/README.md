# Arduino Traffic Light with Pedestrian Button and 7-Segment Countdown

This project simulates a traffic light system with pedestrian crossing control using an Arduino. The system includes a pedestrian button to request a green light for pedestrians, with a countdown displayed on a 7-segment display.


## Features
- **Traffic Light Control:** The system controls a standard 3-light traffic signal for cars (green, yellow, red) and a pedestrian crossing signal (green and red).
- **Pedestrian Button:** When pressed, the system stops traffic, allowing pedestrians to cross safely.
- **Countdown Timer:** A 7-segment display shows a countdown for both the traffic signal's yellow light and the pedestrian crossing phase.
- **Serial Monitor Alerts:** Displays messages such as "Don't cross" and "Cross" to indicate pedestrian crossing phases.

## How It Works
1. **Default Traffic Flow:** The traffic light shows green for cars by default, while the pedestrian signal shows red.
2. **Pedestrian Button Press:** When a pedestrian presses the button, the car light switches to yellow, and a 9-second countdown appears on the 7-segment display.
3. **Pedestrian Crossing:** After the countdown, the car light turns red, and the pedestrian light turns green, allowing pedestrians to cross for 15 seconds.
4. **End of Crossing Phase:** A final 5-second countdown is shown on the 7-segment display before traffic flow resumes with a green light for cars.

## Circuit Diagram

![Traffic Light Circuit Diagram](![Screenshot 2024-09-18 000422](https://github.com/user-attachments/assets/f58a0ab6-cdef-4a61-93f5-971469253771))


## Simulation

- **Software**: [Tinkercad](![https://www.tinkercad.com/](https://www.tinkercad.com/things/6GuXBEefT8O-traffic-lights-with-pedestrian-button/editel?sharecode=5EhVTKDGJFsXZb8ncYfjbS_j5A7uZReOxDUoz8heqfU)) 

