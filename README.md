# Rain Detection System using Arduino

This project is a simple yet effective rain detection system built with an Arduino and a rain sensor module. It is designed to detect water droplets and trigger real-time alerts through an LED, a buzzer, and a motor. This system has practical applications in smart irrigation, automatic window and roof systems, and weather monitoring stations.

## Features

*   **Real-time Rain Detection:** Utilizes a rain sensor module to detect the presence of water.
*   **Analog and Digital Output:** The system can interpret both analog (for intensity) and digital (for presence) signals from the sensor.
*   **Multiple Alerts:** Triggers a visual alert (LED), an audible alert (buzzer), and can activate a motor in response to rainfall.
*   **Adjustable Sensitivity:** The detection threshold can be easily adjusted in the code to suit different needs.

## Hardware Requirements

*   Arduino Uno (or any other compatible board)
*   Rain Sensor Module (with both D0 and A0 outputs)
*   1 x LED (any color)
*   1 x 220Ω Resistor
*   1 x Piezo Buzzer
*   1 x 5V DC Motor
*   1 x L293D Motor Driver IC or a suitable motor driver module
*   Jumper Wires
*   Breadboard

## Software Requirements

*   [Arduino IDE](https://www.arduino.cc/en/software)

## Circuit and Connections

1.  **Rain Sensor Module:**
    *   `VCC` to `5V` on Arduino
    *   `GND` to `GND` on Arduino
    *   `A0` (Analog Output) to `A0` on Arduino
    *   `D0` (Digital Output) to `Pin 2` on Arduino

2.  **LED:**
    *   Connect the longer leg (anode) to `Pin 8` on the Arduino through a 220Ω resistor.
    *   Connect the shorter leg (cathode) to `GND` on the Arduino.

3.  **Buzzer:**
    *   Connect the positive leg to `Pin 9` on the Arduino.
    *   Connect the negative leg to `GND` on the Arduino.

4.  **Motor (with L293D Driver):**
    *   Connect the L293D's `VCC1` (logic power) to `5V` on the Arduino.
    *   Connect the L293D's `VCC2` (motor power) to an external 5V power supply.
    *   Connect the L293D's `GND` to `GND` on the Arduino and the external power supply.
    *   Connect the L293D's `Input 1` to `Pin 10` on the Arduino.
    *   Connect the L293D's `Input 2` to `GND`.
    *   Connect the L293D's `Enable 1,2` to `5V`.
    *   Connect the DC motor to the L293D's `Output 1` and `Output 2`.

## Installation and Usage

1.  **Assemble the Circuit:** Connect all the components as described in the "Circuit and Connections" section.
2.  **Connect the Arduino:** Plug your Arduino board into your computer via USB.
3.  **Open in Arduino IDE:** Open the `rain_detection_system.ino` file in the Arduino IDE.
4.  **Select Board and Port:** Go to `Tools > Board` and select your Arduino board. Then go to `Tools > Port` and select the correct port.
5.  **Upload the Code:** Click the "Upload" button to flash the code onto your Arduino.
6.  **Test the System:**
    *   Open the Serial Monitor (`Tools > Serial Monitor`) at a baud rate of 9600 to see the sensor readings.
    *   Apply some water to the rain sensor plate.
    *   The LED should light up, the buzzer should sound, and the motor should start spinning.
    *   When the sensor plate is dry, the alerts will turn off.

## How It Works

The rain sensor module has a sensing pad with a series of exposed copper traces. When water droplets fall on it, they bridge the traces, reducing the resistance.

*   **Analog Output (A0):** The sensor provides an analog voltage that is inversely proportional to the amount of water on the sensor. A lower analog reading means more rain.
*   **Digital Output (D0):** The module also has a comparator that gives a HIGH or LOW signal based on a threshold set by the onboard potentiometer.

The Arduino continuously reads the analog value from the sensor. If this value drops below a predefined `rainThreshold`, the Arduino activates the LED, buzzer, and motor.
