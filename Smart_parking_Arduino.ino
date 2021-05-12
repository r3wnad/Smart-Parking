#include <LiquidCrystal.h>

//#include <Firebase.h>
//#include <FirebaseArduino.h>
//#include <FirebaseCloudMessaging.h>
//#include <FirebaseError.h>
//#include <FirebaseHttpClient.h>
//#include <FirebaseObject.h>

#include <ArduinoJson.h>

#include <LiquidCrystal.h>

//#include <ESP8266WiFi.h>
#include <Servo.h>
//#include <Wire.h>
//#include <FirebaseArduino.h>

//#define FIREBASE_HOST "parking-2bd7a-default-rtdb.firebaseio.com"                 // the project name address from firebase id
//#define FIREBASE_AUTH "2zbdmr8g46Lnhvi47DTTmiv7s8TaRPGWnc5WPY4Z"            // the secret key generated from firebase

//#define WIFI_SSID "Gearbox Staff"                                             // input your home or public wifi name 
//#define WIFI_PASSWORD "Staff@Gearbox"                                    //password for Wifi
String Available = "";                                                  //availability string
String fireAvailable = "";

LiquidCrystal lcd(41, 39, 37, 35, 33 ,31);

Servo myservo;                          //servo as gate
Servo myservos;                               //servo as gate
//int Empty;                            //available space integer
int allSpace = 5;
int countYes=0;
int carEnter = A0;                      // entry sensor 
int carExited = A1;                   //exi sensor
int TRIG = 13;                  //ultrasonic trig  pin
int ECHO = 12;                // ultrasonic echo pin
//int led = D3;                 // spot occupancy signal
//int pos;
//int pos1;

long duration, distance;

void setup()
{
  Serial.begin(115200);
   myservo.attach(4);      // servo pin to D6
  myservos.attach(5);       // servo pin to D5
  pinMode(TRIG, OUTPUT);      // trig pin as output 
  pinMode(ECHO, INPUT);         // echo pin as input
   pinMode(carExited, INPUT);    // ir as input
  pinMode(carEnter, INPUT);     // ir as input

//WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
//Serial.print("Connecting to ");
//Serial.print(WIFI_SSID);                          // display ssid
//while (WiFi.status() != WL_CONNECTED) {
  //  delay(500);
    //Serial.print("Not connected to the internet");   }

    //Serial.print("Connected to ");
 //Serial.println(WIFI_SSID);
  //Serial.print("IP Address is : ");
 //Serial.println(WiFi.localIP()); 
   //Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);        // begin firebase authentication

 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Smart Parking");
 lcd.setCursor(0,1);
 lcd.print("Slots=");  
 lcd.print(allSpace);                      
}

void loop()
{
 int rem= allSpace - countYes; // available space integer     

   digitalWrite(TRIG, LOW);         // make trig pin low
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);        // make trig pin high
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;    // take distance in cm

//  Serial.print("Centimeter: ");
  //  Serial.println(distance);

     int carEntry = digitalRead(carEnter);      // read ir input
  if (carEntry == LOW) {                     // if high then count and send data
    countYes++;                             //increment count
    Serial.print("Car Entered = " ); 
    Serial.println(countYes );
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slots=");
    lcd.print(allSpace-countYes);
    myservo.write(180);
    delay(2000);
    myservo.write(0);
 
    //Firebase.pushString("/Parking Status/", fireAvailable );    // send string to firebase
    //lcd.clear();
  }
   int carExit = digitalRead(carExited);              //read exit ir sensor
  if (carExit == LOW) {                            //if high then count and send
    countYes--;                                    //decrement count
    Serial.print("Car Exited = " ); 
    Serial.println(countYes);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slots=");
     lcd.print(allSpace- countYes);
      myservos.write(180);
    delay(2000);
    myservos.write(0);
    
      // Firebase.pushString("/Parking Status/", fireAvailable );  // send string to firebase
       //lcd.clear();
   }
   
  
 
  rem = allSpace - countYes;         //calculate available data
   if (distance<6){
    Serial.println("Occupied space");
  }
else{
  Serial.println("");
}
 
//Available = String("Available= ") + String(rem) + String("/") + String(allSpace);       // convert the int to string
  //fireAvailable = String("Available=") + String(rem) + String("/") + String(allSpace);


// lcd.setCursor(0, 0);
 //lcd.print(Available);   
    


}
