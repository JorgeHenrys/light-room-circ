#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <FirebaseJson.h>
#include <ESP8266WiFi.h>





#define FIREBASE_HOST "temperauter-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "lkYpzDu4wuafu3S0bbY1YbwnkTkPA9xpHz0yBS8I"
#define WIFI_SSID "HENRIQUE"

#define WIFI_PASSWORD "DE0ATE100"

int ledRoomA = D1;
int ledRoomB = D2;
int ledRoomC = D3;




void setup() {

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());


  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledRoomA, OUTPUT);
  digitalWrite(ledRoomA, LOW);
  pinMode(ledRoomB, OUTPUT);
  digitalWrite(ledRoomB, LOW);
  pinMode(ledRoomC, OUTPUT);
  digitalWrite(ledRoomC, LOW);

}

void loop() {


  String ledStatus = Firebase.getString("led1");

  if(ledStatus == "room_a_on"){
    Serial.println(ledStatus);
    digitalWrite(ledRoomA, HIGH);
  }
  if(ledStatus == "room_a_off"){
    Serial.println(ledStatus);
    digitalWrite(ledRoomA, LOW);
  }

  if(ledStatus == "room_b_on"){
    Serial.println(ledStatus);
    digitalWrite(ledRoomB, HIGH);
  }
  if(ledStatus == "room_b_off"){
    Serial.println(ledStatus);
    digitalWrite(ledRoomB, LOW);
  }

  if(ledStatus == "room_c_on"){
    Serial.println(ledStatus);
    digitalWrite(ledRoomC, HIGH);
  }
  if(ledStatus == "room_c_off"){
    Serial.println(ledStatus);
    digitalWrite(ledRoomC, LOW);
  }

  

}
