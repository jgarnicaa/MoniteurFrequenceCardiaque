#ifndef LEDP_h
#define LEDP_h
#include <Peripheriques.h>
#include <Arduino.h>

// classe led pour contrôler le comportement de la led qui nous dira si le système fonctionne et nous montre les pulsations
class LEDP : public Peripheriques{
  public:
//méthode pour allumer la led
    void TurnOn();
//méthode pour éteindre la led
    void TurnOff();
};

#endif
