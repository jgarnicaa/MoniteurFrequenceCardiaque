//inclusion de bibliothèques et de classes
#include <Wire.h>
#include "rgb_lcd.h"
#include <LEDP.h>
#include <speaker.h>
#include <Arduino.h>
#include <vector>



//instance des 3 composants à utiliser
rgb_lcd lcd;
LEDP led;
speaker myspeaker;


//Variables nécessaires au fonctionnement du mécanisme
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
unsigned char counter=0;
unsigned int heart_rate=0;
//En utilisant le stl de la classe vector
std::vector<unsigned long> temp(21);
unsigned long sub=0;
volatile unsigned char state = LOW;
bool data_effect=true;
const int max_heartpluse_duty=2000;//you can change it follow your system's request.2000 meams 2 seconds, heart rate is 60/2. System return error if the duty overtrip 2 second.


//Interruption qui permet d'effectuer la mesure
void ICACHE_RAM_ATTR isr()
{ 
    temp[counter]=millis(); //get sys time
    state = !state;    //change LED status
    Serial.println(counter,DEC);
    Serial.println(temp[counter]);
    switch(counter)
      {
       case(0):
       sub=temp[counter]-temp[20];
       Serial.println(sub);
       break;
       default:
       sub=temp[counter]-temp[counter-1];
       Serial.println(sub);
       break;
      }
    
    if(sub>max_heartpluse_duty)//set 2 seconds as max heart pluse duty
      {
        data_effect=0;//sign bit
        counter=0;
        Serial.println("Heart rate measure error,test will restart!" );
        lcd.clear();
        lcd.print("ERROR");
        lcd.setCursor(0, 1);
        lcd.print("Test restart");
        array_init();
       }
    if (counter==20&&data_effect)
    {
      counter=0;
      sum();
    }
    else if(counter!=20&&data_effect)
    counter++;
    else 
    {
      counter=0;
      data_effect=1;
    }
}

//description du port et initialisation du programme
void setup() 
{ 
  led.setPin(D7);
  myspeaker.setPin(D5);
  myspeaker.setVol(50);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  Serial.begin(9600);
  Serial.println("Please press the sensor with your finger");
  lcd.print("Press the sensor");
  delay(2000);//wait finger press ready
  lcd.setCursor(0, 1);
  lcd.clear();
  //initialisation du vecteur à 0
  array_init();
  Serial.println("Heart rate test begin.");
    // Print a message to the LCD.
  lcd.print("Heart rate test begin.");
  delay(3000);
  attachInterrupt(digitalPinToInterrupt(D6), isr, RISING);//set interrupt 0,digital port 6
}


//loop
void loop()
{
  if(state){
    led.TurnOn();
  }else{
    led.TurnOff();
  }
}


//faire le calcul pour pouvoir effectuer la mesure
void sum(){
   if(data_effect)
    {
      try{
        if((temp[20]-temp[0])==0){
          throw "Error: Division by zero!";
          }
      //toutes les 20 secondes nous avons une mesure, 
      //cette variable montre la conversion de la valeur initiale et finale de la mesure et est divisée par cette valeur pour convertir de milliseconde en seconde
      heart_rate=1200000/(temp[20]-temp[0]);//60*20*1000/20_total_time 
      Serial.print("Heart_rate_is:\t");
      Serial.println(heart_rate);
      myspeaker.TurnOn();
      lcd.clear();
      lcd.print("Heart rate is:");
      lcd.setCursor(0,1);
      lcd.print(heart_rate);
      delay(200);
      myspeaker.TurnOff();
      }
      catch (const char* errorMessage){
        printf(errorMessage);
        }
    }
   data_effect=1;//sign bit
}


//initialiser le tableau à 0
void array_init()
{
  for(unsigned char i=0;i!=20;++i)
  {
    temp[i]=0;
  }
  temp[20]=millis();
}

