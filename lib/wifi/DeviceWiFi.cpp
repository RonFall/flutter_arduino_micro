#include "DeviceWiFi.h"

void connectToWiFi(const char *ssid, const char *pass)
{
  Serial.println("Устанавливается соединение с ");
  Serial.print(ssid);

  // Регистрация подключения на основе введенных данных
  WiFi.begin(ssid, pass);

  // Проверка подключения
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  // Установка соединения, если все успешно
  Serial.println("");
  Serial.println("Соединение установлено!");
  Serial.print("IP-адрес: ");
  Serial.println(WiFi.localIP());
}

void loopReconnectToWiFi(const char *ssid, const char *pass)
{
  // Если соединение разорвано происходит переподключение со всеми настройками
  while (WiFi.status() != WL_CONNECTED)
  {
    connectToWiFi(ssid, pass);
  }
}