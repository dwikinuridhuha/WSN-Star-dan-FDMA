#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "printf.h"
#include <string.h>


RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "11111";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
int lm35;
//int button_pin = 2;
//boolean button_state = 0;

void setup() {
//pinMode(button_pin, INPUT);
Serial.begin(9600);
printf_begin();
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.setChannel(100);
//radio.setChannel(105);
radio.stopListening();          //This sets the module as transmitter
radio.printDetails();
}

void loop()
{
  delay(4);
lm35 = analogRead(A0)/ 2.0479;
  
char text[25];
itoa(lm35, text, 10);
//    const char test[200] = text;
//    Serial.println(text);
const char test[]=" Channel 100: Node B";
    strcat(text,test);
    Serial.println(text);
    radio.write(&text, sizeof(text));                  //Sending the message to receiver 
//    delay(5);
}
