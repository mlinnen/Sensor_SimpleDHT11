#ifndef SensorDHT11_h
#define SensorDHT11_h

#include "Arduino.h"
#include <RBD_Timer.h> 
#include "DHT.h"

namespace Sensor
{
  class SensorSimpleDHT11
  {
  public:
    SensorSimpleDHT11(int dataPin, boolean celsius, int frequencySeconds);
    void setup();
    boolean loop();
    float getTemperature();
    float getHumidity();


  private:
    RBD::Timer _fequencyTimer;
    boolean _celsius;
    float _temperature;
    float _humidity;
    int _frequencySeconds;
    DHT *_dht;

  };
}

#endif