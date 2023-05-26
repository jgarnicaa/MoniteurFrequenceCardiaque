#include "speaker.h"

void speaker::TurnOn(){
  analogWrite(pin, vol);
}
void speaker::TurnOff(){
  analogWrite(pin, 0);
}
void speaker::setVol(int v){
  this->vol=v;
}
