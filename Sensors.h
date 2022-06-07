#ifndef Sensors_h
#define Sensors_h

#ifndef data_struct
#define data_struct
struct SensorData {
    float temperature;
    float humidity;
    float lightLevel;
};
#endif

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>


#include <BH1750.h>
#include <Wire.h>



#define DHTPIN 2
#define DHTTYPE DHT22


class SENSORS {
public:
    SENSORS();
    ~SENSORS();

    void init();

    float readData();
    
    SensorData data;
};

#endif