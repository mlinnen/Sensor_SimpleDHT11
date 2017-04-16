# Overview
This arduino library is designed to monitor the DHT11 Temperature/Humidity sensor. 

## Dependencies
This library depends on the following libraries:
* RBD_Timer https://github.com/alextaujenis/RBD_Timer
* DHT-sensor-library https://github.com/adafruit/DHT-sensor-library
* Adafruit_Sensor https://github.com/adafruit/Adafruit_Sensor 

The example Arduino Sketch also depends on the following libraries:
* PubSubClient http://pubsubclient.knolleary.net

You must install the dependent libraries before you compile the examples.

## Examples
### MQTT Sensor Simple DHT11
This example uses the library to measure the temperature and humidity and publish the values to an MQTT broker every 10 seconds.

#### Configuration
The example requires you to fill out the Wifi and MQTT details before it will compile.

1. Copy examples/MQTTCoverDualSwitchSensor/mywifi.sample.h to mywifi.h
2. Edit the mywifi.h file to set the Wifi connection details.
3. Copy examples/MQTTCoverDualSwitchSensor/mymqttbroker.sample.h to mymqttbroker.h
4. Edit the mymqttbroker.h file to set the MQTT broker details.

After you make the changes to the mywifi.h and mymqttbroker.h you should be able to compile the example. 

#### Wiring
TODO

#### Running the example
The mosquitto MQTT broker and client tools are included in this repository in the test/MQTT/mosquitto folder.  You can use the test/MQTT/brokerlocal.bat to start up a local MQTT broker or just use one that is on on your network. 

You can use the test/MQTT/auditlocal.bat to launch the mosquitto_sub.exe to monitor all messages published to the local broker.  Use this if you are running the local broker without any username or password.

If you have a broker on your network that is password protected then use the test/MQTT/audit.bat to launch the mosquitto_sub.exe to monitor all messages published to the broker.  Before you run the audit.bat you should set the following environment variables:
* MQTT_IP - set to the IP of the MQTT Broker
* MQTT_USR - set to the user used to connect to the broker
* MQTT_PWD - set to the password of the user that will connect to the broker.

Once the broker and the audit are running you can go ahead and download the code to the arduino and let it run.

The temperature and humidity values will be published onto MQTT every 10 seconds.


### More Complete Examples
This repository contains more examples on how to use the cover libraries in a more complete way.  [Cover Full Examples](https://github.com/mlinnen/Cover_FullExamples)


