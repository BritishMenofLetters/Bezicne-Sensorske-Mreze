#ifndef Communication_h
#define Communication_h


#include <nRF24L01.h>
#include <RF24.h>


#ifndef data_struct
#define data_struct

struct SensorData {
    float temperature;
    float humidity;
    //float lightLevel;
};
#endif


#define CE_PIN 9
#define CSN_PIN 8
#define CHANNEL 120 // između 0 i 125


class COMM {

public:
    COMM();
    ~COMM();

    //const byte address[6] = "pitar";

    void setAsReceiver();
    void setAsTransmitter();
    
    float readData();
    void sendData(float);

};

#endif