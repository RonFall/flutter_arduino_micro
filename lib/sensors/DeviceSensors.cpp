#include "DeviceSensors.h"
#include <DHT.h>

/* Номер пина датчика температуры и влажности */
uint8_t DHTPin = 10;

#define DHTTYPE DHT11
DHT dht(DHTPin, DHTTYPE);

void loopSendSensorsData()
{
    int temp = dht.readTemperature();
    int hum = dht.readHumidity();
    loopSendDataToRTDB(temp, hum);
}