#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

int relay = 3;
int state = 48;
int ignition = 0;
 
void setup() 
{
  // HC-05 BLUETOOTH
  Serial.begin(9600);
  BT.begin(9600);
 
  // FLIP-FLOP RELAY
  pinMode(relay, OUTPUT); // Assign the relay pin
  digitalWrite(relay, LOW);
}
void loop() 
{
  // Check if data is present from serial port;
  if (BT.available() > 0){

    // Get the current state from BT
    state = BT.read();

    // Check the state of the request
    if (state == 48 && ignition == 1) {
      Serial.println("Ignition off");
      ignition = 0;
    } 
    else if (state == 49 && ignition != 1) {
      Serial.println("Ignition on");
      ignition = 1;
    }

    // Ping the relay
    delay(50);
    digitalWrite(relay, HIGH);
    delay(250);
    digitalWrite(relay, LOW);
  }
  delay(1000);
} 
