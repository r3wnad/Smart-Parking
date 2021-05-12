#include <ArduinoJson.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <SoftwareSerial.h>

String Available = "";                                                  //availability string
String fireAvailable = "";

LiquidCrystal lcd(41, 39, 37, 35, 33 ,31);
SoftwareSerial s(9,10);

Servo myservo;                          //servo as gate
Servo myservos;                               //servo as gate
int allSpace = 5;
int countYes=0;
int state;
int carEnter = A0;                      // entry sensor 
int carExited = A1;                   //exi sensor
int TRIG = 13;                  //ultrasonic trig  pin
int ECHO = 12;                // ultrasonic echo pin

long duration, distance;

void setup()
{
  Serial.begin(115200);
  s.begin(19200);
  myservo.attach(4);      // servo pin to D6
  myservos.attach(5);       // servo pin to D5
  pinMode(TRIG, OUTPUT);      // trig pin as output 
  pinMode(ECHO, INPUT);         // echo pin as input
   pinMode(carExited, INPUT);    // ir as input
  pinMode(carEnter, INPUT);     // ir as input

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
    state = -1;
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
    state = 0;
   }
   
  rem = allSpace - countYes;         //calculate available data
  if (distance<6){
    Serial.println("Occupied space");
  }
  else{
  Serial.println("");
  }

  Serial.println(state);
  s.write(state);
  delay(2500);

}
