#include "DeviceFirebase.h"
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

FirebaseData fireData;
FirebaseConfig fireConfig;
FirebaseAuth fireAuth;

void initFirebaseService(String deviceApiKey, String deviceDatabaseUrl, String deviceEmail, String devicePass)
{
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  // Определение уникального ключа устройства и ссылки на Firebase Realtime Database
  fireConfig.api_key = deviceApiKey;
  fireConfig.database_url = deviceDatabaseUrl;

  // Определение учетных данных для микроконтроллера
  fireAuth.user.email = deviceEmail;
  fireAuth.user.password = devicePass;

  // Получение уникального токена микроконтроллера
  fireConfig.token_status_callback = tokenStatusCallback;

  // Регистрация работы сервиса
  Firebase.begin(&fireConfig, &fireAuth);

  // Получение UID и его отображение
  Serial.println("Получение UID микроконтроллера");
  while ((fireAuth.token.uid) == "")
  {
    Serial.print('.');
    delay(1000);
  }

  Serial.print("Успешно подключено к Firebase!");
}

void loopSendDataToRTDB(int temp, int hum)
{
  String basePath = "/devices/antonov";
  String tempPath = basePath + "/temperature";
  String humpPath = basePath + "/humidity";

  if (Firebase.ready())
  {
    Firebase.setInt(fireData, tempPath, temp);
    Firebase.setInt(fireData, humpPath, hum);
    delay(100);
  }
}