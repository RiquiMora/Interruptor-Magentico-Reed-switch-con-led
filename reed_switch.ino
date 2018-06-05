#include "LowPower.h"

const int pinSwitch = 12; //Pin Reed
const int pinLed = 9; //Pin LED
const int pinBuzzer = 5;
int StatoSwitch = 0;

void setup(){
  pinMode(pinLed, OUTPUT); //Imposto i PIN
  pinMode(pinSwitch, INPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop(){

  StatoSwitch = digitalRead(pinSwitch); //Leggo il valore del Reed
  
  if (StatoSwitch == HIGH){
    digitalWrite(pinLed, HIGH);
    alarma();
  }else{
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuzzer, LOW);
    LowPower.powerDown(SLEEP_15MS, ADC_OFF, BOD_OFF); 
  }
}

void alarma(){
  for(double x = 0; x < 0.92; x += 0.01){
    tone(pinBuzzer, sinh(x+8.294), 10);
    delay(1);
  }
  
  for(double x = 0; x < 0.183258; x += 0.002){
    tone(pinBuzzer, sinh(-5* (x-1.8420681)), 10);
    delay(2);
  }
}

