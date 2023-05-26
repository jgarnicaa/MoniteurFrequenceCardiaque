#ifndef LED_h
#define LED_h

//#include "Arduino.h"

class LED
{
  public:
    LED(int pin);
    void TurnOn();
    void TurnOff();
  private:
    bool Status;
    int _pin;
};

#endif
