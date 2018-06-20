#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
const int pin = 2;
int stateSW;
int count;
int delta;
int coe;

void setup() {
  SerialBT.begin("ESP32");
  pinMode(pin, INPUT);
  stateSW = 0;
  count = 0;
  //delta = 1;
  delta = 5;
  coe = 1;
}

void loop() {
  if(count+coe*delta<  0){coe*=-1;}
  if(count+coe*delta>200){coe*=-1;}
  count+=coe*delta;
  if(count<  0){count=  0;}
  if(count>200){count=200;}
  
  stateSW = digitalRead(pin);
  if(stateSW==0){
    SerialBT.write(count);
  }else{
    SerialBT.write(255);
  }
  delay(10);
}
