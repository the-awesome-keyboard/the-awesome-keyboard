/* ATtiny85 as an I2C Slave            BroHogan                           1/12/11
 * Example of ATtiny I2C slave receiving and sending data to an Arduino master.
 * Gets data from master, adds 10 to it and sends it back.
 * SETUP:
 * ATtiny Pin 1 = (RESET) N/U                      ATtiny Pin 2 = (D3) N/U
 * ATtiny Pin 3 = (D4) to LED1                     ATtiny Pin 4 = GND
 * ATtiny Pin 5 = I2C SDA on DS1621  & GPIO        ATtiny Pin 6 = (D1) to LED2
 * ATtiny Pin 7 = I2C SCK on DS1621  & GPIO        ATtiny Pin 8 = VCC (2.7-5.5V)
 * NOTE! - It's very important to use pullups on the SDA & SCL lines!
 * Current Rx & Tx buffers set at 32 bytes - see usiTwiSlave.h
 * Credit and thanks to Don Blake for his usiTwiSlave code. 
 * More on TinyWireS usage - see TinyWireS.h
 */


#include "TinyWireS.h"                  // wrapper class for I2C slave routines

#define I2C_SLAVE_ADDR 1            // i2c slave address

#define A 0x61
#define Z 0x7A

uint8_t data = A;

void setup() {
  TinyWireS.begin(I2C_SLAVE_ADDR);      // init I2C Slave mode
  TinyWireS.onRequest(requestEvent);    // register event  
}


void loop() {
  tws_delay(100);
}

// sends alphabet
void requestEvent() {
  TinyWireS.send(data);

  if (data < Z) {
    data += 0x01;
  } else {
    data = A;
  }
}



