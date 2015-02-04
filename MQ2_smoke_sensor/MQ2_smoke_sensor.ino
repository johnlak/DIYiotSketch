/*

  MQ-2 Smoke & Gas Alarm

  Current Code
  Created by Derek Erb 24/02/2013
  Modified 26/02/2013

  Requirements :  Arduino Uno & MQ-2 Sensor
                  Both A pins and left H pin connected to 5V out
                  Right H pin connected to GND
                  Both B pins, and right H pin, connected to 22k ohms resistor and A0

  0.01 Read value, map (0 to 100), display and check for too high
*/

// Sensor value read from analog pin (range from 0 to 1023)
int iSensorValue = 0;

// Mapped value from 0 to 100
byte bySensorVal = 0;

//////////////////////////////////////////////////////
//
// SETUP
//
void setup() {
  Serial.begin(115200);
}

//////////////////////////////////////////////////////
//
// LOOP
//
void loop() {

  // Read input value on A0 and map it from 0 to 100
  iSensorValue = analogRead(A0);
  bySensorVal = map(iSensorValue, 0, 1023, 0, 100);

Serial.print("@");
Serial.print(bySensorVal);
Serial.print("#");

  // Loop 10 times per second
  delay(100);
}

