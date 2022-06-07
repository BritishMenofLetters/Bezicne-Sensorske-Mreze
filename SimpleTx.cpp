// SimpleTx - the sender

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

const byte address[6] = {"1node"};

RF24 radio(CE_PIN, CSN_PIN);

struct SensorData
{
  float temp;
  float hum;
};

SensorData dataToSend;

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once every 10 seconds

void send();

void setup()
{
  Serial.begin(9600);

  Serial.println(F("SimpleTx Starting"));
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(109);
  radio.setPALevel(RF24_PA_MAX);
  radio.setRetries(3, 5); // delay, count
  radio.openWritingPipe(address);

  randomSeed(analogRead(0));
}

void loop()
{
  currentMillis = millis();
  if (currentMillis - prevMillis >= txIntervalMillis)
  {
    send();
    prevMillis = millis();
  }
}

void send()
{

  bool rslt;
  dataToSend.temp = random(10, 20);
  dataToSend.hum = random(20, 30);

  rslt = radio.write(&dataToSend, sizeof(dataToSend));
  // Always use sizeof() as it gives the size as the number of bytes.
  // For example if dataToSend was an int sizeof() would correctly return 2

  Serial.print("Data Sent ");
  Serial.print(dataToSend.temp);
  Serial.print(" ");
  Serial.print(dataToSend.hum);

  if (rslt)
  {
    Serial.println("  Acknowledge received");
  }
  else
  {
    Serial.println("  Tx failed");
  }
}