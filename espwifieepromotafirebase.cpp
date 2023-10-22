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
# include "espwifieepromotafirebase.h"

  myClass::myClass(int){
;
  }
 
  void myClass::PusleSound(char count,double Freq){
    char i;
    bool fDispEn = true;
    if (!fDispEn) return;
    for (i=0;i<count;i++)
       {
         tone(bSound,Freq);
         delay(50);
          noTone(bSound);
          digitalWrite(bSound,LOW); 
           delay(50);            // delay for next retry
        }
  }

//////////////////////////////////////////////////////////////////
  String myClass::readFirebaseString(const String& path){
    if (!Firebase.getString(firebaseData, path)) {
    Serial.println("Failed to read Firebase: " + firebaseData.errorReason());
  }
  return firebaseData.stringData();
  }

//////////////////////////////////////////////////////

  void myClass::saveCurrentWiFiCredential(int currentCredential){
    int address = 481;
    EEPROM.put(address, currentCredential);
    EEPROM.commit();
}
   int myClass::readCurrentWiFiCredential(){
    int address = 481;
    int currentCredential;
    int* currentCredentialPtr = &currentCredential; // Sử dụng con trỏ để truyền địa chỉ của biến
    EEPROM.get(address, *currentCredentialPtr); // Truyền địa chỉ của biến
    return currentCredential;
}

///////////////////////////////////////////////////////////////////////

void myClass::saveWiFiCredentials(const WiFiCredentials& credentials, int index){
    int address = index * sizeof(WiFiCredentials);
    EEPROM.put(address, credentials);
    EEPROM.commit();
}
WiFiCredentials myClass::readWiFiCredentials(int index) {
  WiFiCredentials credentials;
  int address = index * sizeof(WiFiCredentials);
  EEPROM.get(address, credentials);
  return credentials;
}
void myClass::printSavedWiFiCredentials() {
  for (int i = 0; i < 5; i++) {
    WiFiCredentials credentials = readWiFiCredentials(i);
    Serial.print("WiFi ");
    Serial.print(i + 1);
    Serial.print(" - SSID: ");
    Serial.print(credentials.ssid);
    Serial.print(", Password: ");
    Serial.println(credentials.password);
  }
}

//////////////////////////////////////////////////////////

  void myClass::onoffin1(int valueIn1){
    if (valueIn1 != previousValueIn1) {
    // Giá trị `valueIn2` đã thay đổi
    if (deBug == 1) {
      Serial.print(" valueIn1: ");
      Serial.println(valueIn1);
    }
    // Gửi giá trị mới lên Firebase
    String firebasePath = "thietbi:" + apSuffix + "in1";
    Firebase.setInt(firebaseData, firebasePath.c_str(), valueIn1);
    // Cập nhật giá trị previousValueIn2
    previousValueIn1 = valueIn1;
  }
  }
  void myClass::onoffin2(int valueIn2){
    if (valueIn2 != previousValueIn2) {
    // Giá trị `valueIn2` đã thay đổi
    if (deBug == 1) {
      Serial.print(" valueIn2: ");
      Serial.println(valueIn2);
    }
    // Gửi giá trị mới lên Firebase
    String firebasePath = "thietbi:" + apSuffix + "in2";
    Firebase.setInt(firebaseData, firebasePath.c_str(), valueIn2);
    // Cập nhật giá trị previousValueIn2
    previousValueIn2 = valueIn2;
  }
  }
  void myClass::onoffin3(int valueIn3){
    if (valueIn3 != previousValueIn3) {
    // Giá trị `valueIn2` đã thay đổi
    if (deBug == 1) {
      Serial.print(" valueIn3: ");
      Serial.println(valueIn3);
    }
    // Gửi giá trị mới lên Firebase
    String firebasePath = "thietbi:" + apSuffix + "in3";
    Firebase.setInt(firebaseData, firebasePath.c_str(), valueIn3);
    // Cập nhật giá trị previousValueIn2
    previousValueIn3 = valueIn3;
  }
  }
  void myClass::onoffin4(int valueIn4){
    if (valueIn4 != previousValueIn4) {
    // Giá trị `valueIn2` đã thay đổi
    if (deBug == 1) {
      Serial.print(" valueIn4: ");
      Serial.println(valueIn4);
    }
    // Gửi giá trị mới lên Firebase
    String firebasePath = "thietbi:" + apSuffix + "in4";
    Firebase.setInt(firebaseData, firebasePath.c_str(), valueIn4);
    // Cập nhật giá trị previousValueIn2
    previousValueIn4 = valueIn4;
  }
  }
  //////////////////////////////////////////////

  
  //void myClass::connectToWiFi(){

  