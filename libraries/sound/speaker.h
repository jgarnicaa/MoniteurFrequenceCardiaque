#ifndef speaker_h
#define speaker_h
#include <Peripheriques.h>
#include <Arduino.h>
//classe de haut-parleur qui nous permet d'émettre le son à la fin d'une mesure
class speaker: public Peripheriques{

  public:

//méthode pour allumer le haut-parleur
    void TurnOn();
//méthode pour éteindre le haut-parleur
    void TurnOff();
//méthode pour régler le volume du haut-parleur
    void setVol(int v);
  private:
//attribut qui indique le niveau de volume du haut-parleur
    int vol=0;
};
#endif
