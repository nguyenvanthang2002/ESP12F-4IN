#ifndef espwifieepromotafirebase_h
# define espwifieepromotafirebase_h
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FirebaseESP8266.h>
#include <ArduinoJson.h>
#include <EEPROM.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <WiFiClientSecure.h>//
#include <CertStoreBearSSL.h>//
#include <time.h>//
# include "Arduino.h"
#define bSound 12
#define RL 2
#define in1 16
#define in2 14
#define in3 5
#define in4 4
struct WiFiCredentials {
  char ssid[32];
  char password[64];
};

extern FirebaseData firebaseData;
extern int deBug;
extern String apSuffix;

extern String macAddress;

class myClass {
      public:
        myClass(int);

         String readFirebaseString(const String& path);

         void saveCurrentWiFiCredential(int currentCredential);
         int readCurrentWiFiCredential();

         void saveWiFiCredentials(const WiFiCredentials& credentials, int index);
         WiFiCredentials readWiFiCredentials(int index);
         void printSavedWiFiCredentials();

         void update(String url);

         void PusleSound(char count,double Freq);

         void connectToWiFi();

         void onoffin1(int valueIn1);
         void onoffin2(int valueIn2);
         void onoffin3(int valueIn3);
         void onoffin4(int valueIn4);


      private:
        int previousValueIn1 = -1;
        int previousValueIn2 = -1;
        int previousValueIn3 = -1;
        int previousValueIn4 = -1;

};

#endif