#include <WiFi.h>

/*!
Подключение к Wi-Fi
\param[in] ssid Имя точки доступа (Wi-Fi)
\param[in] pass Пароль точки доступа (Wi-Fi)
*/
void connectToWiFi(const char *ssid, const char *pass);

/*!
Переподключение к Wi-Fi, если соединение разорвано
\param[in] ssid Имя точки доступа (Wi-Fi)
\param[in] pass Пароль точки доступа (Wi-Fi)
*/
void loopReconnectToWiFi(const char *ssid, const char *pass);