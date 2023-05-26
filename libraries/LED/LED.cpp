#include "Arduino.h"
#include "LED.h"

LED::LED(int pin){
  _pin=pin;
  pinMode(_pin, OUTPUT);
}

void LED::TurnOn(){

  digitalWrite(_pin,HIGH);

}

void LED::TurnOff(){

  digitalWrite(_pin,LOW);

}
