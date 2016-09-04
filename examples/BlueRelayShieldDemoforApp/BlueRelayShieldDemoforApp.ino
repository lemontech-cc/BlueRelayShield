/*
    Lemontech BlueRelay Shield    
    Demo sketch for App

    v 1.0 - 10/06/2015
*/

#include <SoftwareSerial.h>

#define BT_TX_PIN  3
#define BT_RX_PIN  4
#define BT_AT_PIN  5
#define RELAY1_PIN 6
#define RELAY2_PIN 7

SoftwareSerial mySerial(BT_TX_PIN, BT_RX_PIN);

boolean relay1Status;
boolean relay2Status;

void setup() {
  
  // Configure Bluetooth module in "transparent mode"
  pinMode(BT_AT_PIN, OUTPUT);
  digitalWrite(BT_AT_PIN, LOW);  

  // Relays default status OFF
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY1_PIN, LOW);
  relay1Status = false;
  relay2Status = false;  

  // Setup serial communication
  Serial.begin(9600);
  mySerial.begin(9600);
  
  Serial.println("Lemontech BlueRelay Shield - Demo sketch");
  Serial.println();
  Serial.println("Type AT commands (use CR+LF as line terminator)");
  Serial.println();
}

void loop() {
  
  // New char from Bluetooth
  if (mySerial.available()) {
    
    char in = mySerial.read();
    switch(in) {
      
      case 'a':
        Serial.println("Toggle RELAY1");
        relay1Status = !relay1Status;
        digitalWrite(RELAY1_PIN, relay1Status);
        break;

      case 'b':
        Serial.println("Toggle RELAY2");
        relay2Status = !relay2Status;
        digitalWrite(RELAY2_PIN, relay2Status);
        break;

      case 'c':
        Serial.println("Send RELAY1 status");
        mySerial.println(relay1Status);
        break;

      case 'd':
        Serial.println("Send RELAY2 status");
        mySerial.println(relay2Status);
        break;        
    }        
  }
}
