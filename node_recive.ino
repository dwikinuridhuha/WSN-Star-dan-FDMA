#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include "printf.h"

RF24 radio(9, 10); // CE, CSN
const byte address_0[6] = "00000";
const byte address_1[6] = "11111";

void setup() {
  Serial.begin(9600);
//  printf_begin();
  radio.begin();
  radio.openReadingPipe(0, address_0);   //Setting the address at which we will receive the data
  radio.openReadingPipe(1, address_1);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.startListening();              //This sets the module as receiver
//  radio.printDetails();
}
void loop() {
  radio.setChannel(100);
  if(radio.available()){
    char text[200] = "";                 //Saving the incoming data
    radio.read(&text, sizeof(text));    //Reading the data
    Serial.println(text);
    radio.setChannel(110);
    char text1[200] = "";                 //Saving the incoming data
    radio.read(&text1, sizeof(text1));    //Reading the data
    Serial.println(text1);
    radio.setChannel(100);
  }
}
