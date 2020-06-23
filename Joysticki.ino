#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio); 
const uint16_t node01 = 01;  
const uint16_t node00 = 00;
//Joystick Analoget fillohen ne 0
int a1 = 0;
int a2 = 0;
void setup() {
    SPI.begin();
  radio.begin();
  network.begin(90, node00);
  radio.setDataRate(RF24_2MBPS);

}

void loop() {
  a1 = analogRead(A0);
  a2 = analogRead(A1);
  if (a1>300) {
    a1 = 1;
  }
  else if (-300<a1<300) {
    a1 = 0;
  }
  else if (a1<-300) {
    a1 = -1;
  }
  if (a2>300) {
    a2 = 1;
  }
  else if (-300<a2<300) {
    a2 = 0;
  }
  else if (a2<-300) {
    a2 = -1;
  }
  network.update();
  RF24NetworkHeader header1(node00);    // Adressa ku te dhenat shkojn
  bool ok3 = network.write(header1, &a1, sizeof(a1)); // Dergo te dhena
  bool ok1 = network.write(header1, &a2, sizeof(a2));
}
