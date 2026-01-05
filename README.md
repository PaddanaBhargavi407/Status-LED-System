# Status-LED-System
# ESP32 Status LED System

## 📌 Project Overview
This project implements a **Status LED System** using an ESP32 microcontroller.  
The LED behavior changes based on user button inputs using **non-blocking timing (`millis()`)**.

---

## 🎯 Project Objectives
- Blink LED **slowly** by default
- Blink LED **fast** when Button 1 is pressed
- **Turn OFF LED** when Button 2 is pressed and held for 3 seconds

---

## 🛠️ Hardware Used
- ESP32 Development Board
- 1 × LED
- 1 × 220Ω Resistor
- 2 × Push Buttons
- Jumper Wires
- USB Cable

---

## 🔌 Pin Configuration

| Component | GPIO Pin |
|---------|----------|
| LED | LED_BUILTIN (GPIO 2) |
| Button 1 (Fast/Slow) | GPIO 4 |
| Button 2 (OFF – 3s Hold) | GPIO 5 |

> Buttons use **INPUT_PULLUP**, so no external pull-up resistors are required.

---

## ⚙️ Software & Tools
- Visual Studio Code
- PlatformIO Extension
- Arduino Framework
- Git & GitHub

---

## 🧠 Working Logic
1. LED blinks **slowly** by default.
2. When **Button 1** is pressed, LED blinks **faster**.
3. When **Button 2** is held for **3 seconds**, the LED turns OFF permanently.
4. Timing is handled using `millis()` for **non-blocking execution**.

---

## 📂 Project Structure
