#include <Arduino.h>
 
#ifndef LED_BUILTIN

  #define LED_BUILTIN 2

#endif
 
const int button1Pin = 4;  // Button to toggle fast/slow blink

const int button2Pin = 5;  // Button to turn off LED after 3s hold
 
unsigned long previousMillis = 0;

unsigned long blinkInterval = 1000; // Default slow blink

bool ledState = LOW;
 
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(button1Pin, INPUT_PULLUP);

  pinMode(button2Pin, INPUT_PULLUP);

}
 
void loop() {

  // Check button1 state for blink speed

  if (digitalRead(button1Pin) == LOW) {

    blinkInterval = 200; // Fast blink

  } else {

    blinkInterval = 1000; // Slow blink

  }
 
  // Check button2 hold duration

  static unsigned long button2PressTime = 0;

  if (digitalRead(button2Pin) == LOW) {

    if (button2PressTime == 0) {

      button2PressTime = millis();

    } else if (millis() - button2PressTime >= 3000) {

      digitalWrite(LED_BUILTIN, LOW); // Turn off LED

      return; // Skip blinking

    }

  } else {

    button2PressTime = 0; // Reset if released

  }
 
  // Blink logic using millis()

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= blinkInterval) {

    previousMillis = currentMillis;

    ledState = !ledState;

    digitalWrite(LED_BUILTIN, ledState);

  }

}
 