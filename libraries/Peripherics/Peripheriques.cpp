#include "Arduino.h"
#include "Peripheriques.h"

void Peripheriques::setPin(int pin){
  this->pin=pin;
  pinMode(pin, OUTPUT);
}
