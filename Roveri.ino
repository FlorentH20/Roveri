#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);     
const uint16_t this_node = 00;   
const uint16_t node01 = 01;
int motordjathtas1 = 4;
int motordjathtas2 = 5;
int motormajtas1 = 6; 
int motormajtas2 = 7;
     
void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  
  radio.setDataRate(RF24_2MBPS);
  pinMode(motordjathtas1, OUTPUT);
  pinMode(motormajtas1, OUTPUT);
  pinMode(motordjathtas2, OUTPUT);
  pinMode(motormajtas2, OUTPUT);

}

void loop() {
  network.update();
  //Pranimi
  while ( network.available() ) {    
    RF24NetworkHeader header;
    unsigned long gjendja1;
    unsigned long gjendja2;
    network.read(header, &gjendja1, sizeof(gjendja1));
    network.read(header, &gjendja2, sizeof(gjendja2));
  
  if (gjendja1 == 0 && gjendja2 == 0){
    digitalWrite(motordjathtas1, LOW);
    digitalWrite(motordjathtas2, LOW);
    digitalWrite(motormajtas1, LOW);
    digitalWrite(motormajtas2, LOW);
  }
  else if (gjendja1 == 1 && gjendja2 == 0) {
    digitalWrite(motordjathtas1, HIGH);
    digitalWrite(motordjathtas2, LOW);
    digitalWrite(motormajtas1, HIGH);
    digitalWrite(motormajtas2, LOW);
  }
  else if (gjendja1 == -1 && gjendja2 == 0) {
    digitalWrite(motordjathtas1, LOW);
    digitalWrite(motordjathtas2, HIGH);
    digitalWrite(motormajtas1, LOW);
    digitalWrite(motormajtas2, HIGH);
  }
  else if (gjendja1 == 0 && gjendja2 == 1){
    digitalWrite(motordjathtas1, HIGH);
    digitalWrite(motordjathtas2, LOW);
    digitalWrite(motormajtas1, LOW);
    digitalWrite(motormajtas2, HIGH);
  }
    else if (gjendja1 == 0 && gjendja2 == -1) {
    digitalWrite(motordjathtas1, LOW);
    digitalWrite(motordjathtas2, HIGH);
    digitalWrite(motormajtas1, HIGH);
    digitalWrite(motormajtas2, LOW);}}}
