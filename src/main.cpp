#include "DeviceWiFi.h"
#include "DeviceFirebase.h"
#include "DeviceSensors.h"

// Подключение к WiFi
const char *wifiSsid = "wifi_name";
const char *wifiPass = "wifi_pass";

// Подключение к Firebase
/* Уникальный ключ микроконтроллера, определяемый в Google Cloud */
String deviceApiKey = "device_api_key";

/* Адрес Firebase Realtime Databse */
String deviceDatabaseUrl = "device_database_url";

/* Электронная почта микроконтроллера */
String deviceEmail = "device_email";

/* Пароль микроконтроллера */
String devicePass = "device_pass";

void setup()
{
  Serial.begin(115200);
  delay(10);

  connectToWiFi(wifiSsid, wifiPass);

  initFirebaseService(deviceApiKey, deviceDatabaseUrl, deviceEmail, devicePass);
}

void loop()
{
  loopReconnectToWiFi(wifiSsid, wifiPass);
  loopSendSensorsData();
}