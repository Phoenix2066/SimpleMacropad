# Simple Macro Pad 
## (Arduino + Python)

A custom macro pad built using an Arduino Uno, push buttons, an I2C LCD display, and a Python script on a PC.  
It allows physical buttons to trigger keyboard shortcuts or actions on a computer.

---

## Features

- 4 programmable push buttons
- LCD display shows button presses
- Serial communication between Arduino and PC
- Python script triggers keyboard shortcuts/actions
- Expandable design for more buttons and actions

---

## Hardware Used

- Arduino Uno
- 4 Push Buttons
- 16x2 I2C LCD Display (address: 0x27)
- Breadboard and jumper wires
- USB cable

---

## Wiring

### Buttons
- Button 1 → Pin 2  
- Button 2 → Pin 3  
- Button 3 → Pin 4  
- Button 4 → Pin 5  
- Other side of each button → GND  
- Uses INPUT_PULLUP mode (active LOW logic)

### LCD (I2C)
- VCC → 5V  
- GND → GND  
- SDA → A4  
- SCL → A5  

---

## Software Requirements

### Arduino
- Arduino IDE
- Library: LiquidCrystal_I2C

### Python Dependencies

Install required packages:
```
pip install pyserial pyautogui
```
- pyserial → reads serial data from Arduino  
- pyautogui → triggers keyboard/mouse actions  

---

## How It Works

1. Arduino detects button presses  
2. Sends data over Serial USB  
   - Example: `0_p` → button 0 pressed  
   - Example: `0_r` → button 0 released  
3. Python script reads serial input  
4. Python executes mapped keyboard shortcuts or actions  

---

## Project Structure
```
arduino-macropad/
├── arduino/
│   └── sketch.ino
├── pc-controller/
│   └── controller.py
|   └── requirements.txt
├── schematics/
│   └── circuit.png
└── README.md
```
---

## Future Improvements

- Add more buttons for extra macros
- Improve button debouncing
- Convert to USB HID device (no Python needed)
- Add custom key mapping system
- Build Desktop UI for easy mapping interface

---

## License

This project is licensed under the MIT License.

---
