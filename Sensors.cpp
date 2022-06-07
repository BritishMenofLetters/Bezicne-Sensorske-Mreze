#include "Sensors.h"


DHT dht(DHTPIN, DHTTYPE);
//BH1750 lightMeter;


SENSORS::SENSORS() {}
SENSORS::~SENSORS() {}


void SENSORS::init() {
    //DHR
    dht.begin();

    // LightMeter
  //  Wire.begin();
 //   lightMeter.begin();     
}

float SENSORS::readData() {


    return 5.4;
}