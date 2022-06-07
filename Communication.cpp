#include "Communication.h"
#include <SPI.h>

const byte address[6] = "pitar";


RF24 radio(CE_PIN, CSN_PIN);

COMM::COMM() {}
COMM::~COMM() {}


void COMM::setAsTransmitter() {

    
    /*if (!radio.begin()) {                    // inicijalizacija radio objekta -> radio.begin
        Serial.println(F("Radio hardware not responding!"));
        while(1) {}                         // zadrži program u beskonacnoj petlji da se spriječe daljni errori
    }
     */                      
    radio.begin();
    Serial.println(F("Ide dalje"));
    radio.setDataRate(RF24_250KBPS);        //! RF24_250KBPS neće raditi za ne-pulsne module
    radio.setChannel(CHANNEL);
    radio.setPALevel(RF24_PA_MIN);
    radio.setRetries(3, 5);                 // delay, count - oba idu 0 do 15

    radio.openWritingPipe(address);         // postavljanje adrese odašiljača
    radio.stopListening();                  // postavljanje modula kao odašiljač
}

void COMM::setAsReceiver() {

    /*if (!radio.begin()) {                    // inicijalizacija radio objekta -> radio.begin
        Serial.println(F("Radio hardware not responding!"));
        while(1) {}                         // zadrži program u beskonacnoj petlji da se spriječe daljni errori
    }*/

    radio.begin();
    Serial.println(F("Ide dalje"));
    radio.setDataRate(RF24_250KBPS);        //! RF24_250KBPS neće raditi za ne-pulsne module
    radio.setChannel(120);
    radio.setPALevel(RF24_PA_MIN);
    
    radio.openReadingPipe(1, address);      // postavljanje adrese prijamnika
    radio.startListening();                 // postavljanje modula kao prijamnik
}

void COMM::sendData(float data) {                      //? Argument staviti SensorData

    //char data[32] = "Podaci";               //TODO: izbrisat kasnije

    if(!radio.write(&data, sizeof(data))) {
        Serial.println("Tx failed");    
    }
    else{
        Serial.println("Uspilo");
    }

}

float COMM::readData() {                      //? Staviti da vraća SensorData tip podatka

    //if(radio.available()) {                 // provjeri je su li podaci dosli
        float readData;                //TODO: kasnije izbrisati
        radio.read(&readData, sizeof(float));    // procitaj primljene podatke
        return readData;
   // }

    //SensorData noData = {0, 0};
   // return 5.5;
}