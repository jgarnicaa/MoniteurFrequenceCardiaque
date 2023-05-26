#ifndef Peripheriques_h
#define Peripheriques_h
#include "Arduino.h"

//classe abstraite qui nous donnera le comportement des périphériques du projet
class Peripheriques{
  public:
//méthode pour allumer les Peripheriques
    virtual void TurnOn();
//méthode pour éteindre les Peripheriques
    virtual void TurnOff();
//Méthode qui nous indique par quelle broche le périphérique est connecté à l'esp8266
    void setPin(int pin);


  protected:
    int pin;

};


#endif
