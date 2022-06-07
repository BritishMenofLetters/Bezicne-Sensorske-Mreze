#ifndef structures_h
#define structures_h

#include <Arduino.h>

#ifndef data_struct
#define data_struct
struct SensorData {
    float temperature;
    float humidity;
    //float lightLevel;
};
#endif


void printSensorData(SensorData data){
    Serial.print(F("Temperature:\t\t" ));
    Serial.println(data.temperature);

    Serial.print(F("Humidity:\t\t" ));
    Serial.println(data.humidity);

    Serial.print(F("LightLevel:\t\t" ));
    //Serial.println(data.lightLevel);

    Serial.println("------------------------");
}


#endif