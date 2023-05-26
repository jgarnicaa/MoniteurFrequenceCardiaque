#include "LEDP.h"

void LEDP::TurnOn(){
  digitalWrite(pin,HIGH);
}

void LEDP::TurnOff(){
  digitalWrite(pin,LOW);
}
