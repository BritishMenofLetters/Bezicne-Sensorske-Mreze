
#include "Communication.h"
#include "Sensors.h"
#include "structures.h"

SENSORS     sensors;
COMM        communication;
SensorData  data;

void setup() {
    Serial.begin(9600);
    sensors.init();
    Serial.println(F("Test"));

   // sensors.init();
   
    communication.setAsTransmitter();

   //communication.setAsReceiver();

}

void loop()
{
    
    float tempera = communication.readData();
    Serial.println(tempera);
    //communication.sendData(6.55555555555);
    //delay(100);

}