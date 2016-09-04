/*
    Lemontech BlueRelay Shield    
    Demo sketch

    v 1.0 - 19/06/2014
*/


#include <SoftwareSerial.h>

#define BT_TX_PIN  3
#define BT_RX_PIN  4
#define BT_AT_PIN  5

SoftwareSerial btSerial(BT_TX_PIN, BT_RX_PIN);

void setup() {

  // Set the AT pin high to send commands to the HC-05 module
  pinMode(BT_AT_PIN, OUTPUT);
  digitalWrite(BT_AT_PIN, HIGH);
  
  // Init the software serial between Arduino and the HC-05 module
  btSerial.begin(9600);
  
  // Init the hardware serial between Arduino and the PC
  Serial.begin(9600);
  Serial.println("Lemontech BlueRelay Shield - Demo sketch");
  Serial.println();
  Serial.println("Type AT commands (use CR+LF as line terminator)");
  Serial.println();
}

void loop() {
  
  // Send to the Bluetooth module what we get from the PC and viceversa
  if (btSerial.available()) Serial.write(btSerial.read());
  if (Serial.available()) btSerial.write(Serial.read());
}
