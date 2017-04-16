#include "Arduino.h"
#include "Sensor_SimpleDHT11.h"

#define DHTTYPE DHT11

namespace Sensor
{
  SensorSimpleDHT11::SensorSimpleDHT11(int dataPin, boolean celsius, int frequencySeconds)
  {
    _dht = new DHT(dataPin, DHTTYPE);
    // Dont allow for a sample of less than 2 seconds
    if (frequencySeconds<2) {_frequencySeconds=2;}
    else {_frequencySeconds = frequencySeconds;}
    _celsius = celsius;
  }

  void SensorSimpleDHT11::setup()
  {
    _fequencyTimer.setTimeout(_frequencySeconds * 1000);
    _fequencyTimer.restart();
  }

  boolean SensorSimpleDHT11::loop()
  {
    // This is the service loop that is called from the main program and will update the state of this component.
    boolean newReadingAvailable = false;

    // Check if it is time to take a new reading
    if (_fequencyTimer.isExpired())
    {
      newReadingAvailable = true;
      _fequencyTimer.setTimeout(_frequencySeconds * 1000);
      _fequencyTimer.restart();
      _temperature = _dht->readTemperature(!_celsius);
      _humidity = _dht->readHumidity();
    }


    // Return true if a new sesnor value is available
    return newReadingAvailable;
  }

  float SensorSimpleDHT11::getTemperature()
  {
    return _temperature;
  }

  float SensorSimpleDHT11::getHumidity()
  {
    return _humidity;
  }
}
