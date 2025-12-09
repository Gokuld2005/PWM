#include "BluetoothSerial.h"
const int ledPin = 26;  // 16 corresponds to GPIO 16
int dutyCycle1 = 100;
int dutyCycle2 = 150;
int dutyCycle3 = 250;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif
#if !defined(CONFIG_BT_SPP_ENABLED)
#error  Serial Bluetooth not available or not enabled. It is only available for the ESP32  chip.
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
   pinMode(ledPin, OUTPUT);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available() > 0) {
  if (SerialBT.available() > 0) {
    
    // Read the entire command as a string
  char command = (char)SerialBT.read();  // Read input until newline

    // Trim whitespace
    //command.trim();

    // Perform actions based on the received command
    if (command == '0') 
    {
      analogWrite(ledPin, LOW);  // Turn on the LED
      Serial.println("LED is OFF");
      SerialBT.println("LED is OFF");
    }.
    
    else if (command == '1') 
    {
      analogWrite(ledPin, dutyCycle1);  // Turn on the LED
      Serial.println("LED is dim");
      SerialBT.println("LED is dim");
    } 
    else if (command == '2') 
    {
      analogWrite(ledPin, dutyCycle2);  // Turn off the LED
      Serial.println("LED is medium");
      SerialBT.println("LED is medium");
    }
    else if (command == '3') 
    {
      analogWrite(ledPin, dutyCycle3);  // Turn off the LED
      Serial.println("LED is full");
      SerialBT.println("LED is full");
    }  
    else {
      Serial.println("no value declared ");
      SerialBT.println("no value declared ");
    }
  } 

  delay(200);
}}
