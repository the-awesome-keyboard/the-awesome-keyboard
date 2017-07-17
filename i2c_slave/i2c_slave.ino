// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

const int MY_ID = 1;
const int BUTTON_PIN = 8; 
int buttonState = 0;
char value = '_';

void setup() {
  Wire.begin(MY_ID);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    value = 'a';
  } else {
    value = '_';
  }
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(value); // respond with message of 6 bytes
  // as expected by master
}
