#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "smart-parking-7f5b6.firebaseio.com"                 // the project name address from firebase id
#define FIREBASE_AUTH "suAkUQ4wXRPW7nA0zJQVsx3H2LmeBDPGmfTMBHCT"            // the secret key generated from firebase

#define ssid "GEARBOX STAFF"                                             // input your home or public wifi name 
#define password "Staff@Gearbox"                                    //password for Wifi
SoftwareSerial s(D1,D0);
byte i;
int allSpace = 5;
int countYes = 0;
int rem;
String Available;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  s.begin(19200);
  while(!Serial) continue;
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly:
  i = s.read();
  Serial.println(i, DEC);
  
  if (i==0){
    countYes--;
    Firebase.pushString("Parking Status/", Available);
  }
  else{
    countYes++;
    Firebase.pushString("Parking Status/", Available);
  }

  rem = allSpace - countYes;
  Available = String("Available= ") + String(rem) + String("/") + String(allSpace);
  
}
