*/
#include <SHT1x.h>
#define dataPin 10
#define clockPin 11
#include <NewSoftSerial.h>
#define SP2_RX 2
#define SP2_TX 3

NewSoftSerial mySerial(SP2_RX, SP2_TX); // 2 is RX, 3 is TX

SHT1x sht1x(dataPin,clockPin);

int m, i, j;
byte hexread[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte initREAD[] = {0xAA, 0x00, 0x44, 0x44, 0xA8};
int x;


// These constants won't change:
const int analogPin0 = 0;    // pin that the sensor is attached to
const int analogPin1 = 1;
const int analogPin2 = 2;
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 60;   // an arbitrary threshold level that's in the range of the analog input
//int A = 600;
//int B = 600;
//int C = 600;
int cal_threshold;
int sensorValue;
int state;
int lastState;
void setup() {
   mySerial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
  Serial.flush();
 
 
}
 
void loop() {
  // read the value of the potentiometer:
  // Serial.flush();
   // wait for incoming data
  //if (Serial.available() < 1) return; // if serial empty, return to loop().
  
	checkTemperature();
	checkDistance();
    checkRoadCondition();
    
	switch(state){
      case 0:
      Serial.println("Rain Stopped");
      break;
     case 1:
      Serial.println("Yellow: Be Aware");
      break;
     case 2:
      Serial.println("Orange: Be Prepared");
      break;
      case 3:
        Serial.println("Red: Take Action");
       break;
     default:
       Serial.println("Error: In water Sensor");
    }

  
  delay(3000);

}

  void checkDistance(){
  for (m=0; m<5; m++){
    // send the request byte
    mySerial.print(initREAD[m],BYTE);
    }
    i = 0;
    while(mySerial.available() && x != 0xA8)    
      {
       hexread[i] = mySerial.read();
       i++;
      }
     for (j = 3; j < (6); j = j+1) {
     Serial.print(hexread[j]);
      }
      Serial.print(".");
    for (j = 6; j < (i-2); j = j + 1) {
    Serial.print(hexread[j]);
    }
    Serial.println("m");
    delay(3000);
  
  }

  void checkTemperature(){
   float temp_c;
   //temp_c = 8;
   temp_c = sht1x.readTemperatureC();
   //Serial.println(temp_c, DEC);
   //Serial.println("C /");
  
   if( (temp_c >= -5)  && (temp_c <= 7)){
       Serial.println("Danger: Black Ice");
   }
  else if ((temp_c >= 8)&&(temp_c <=9)){
      Serial.print("Carefull: Cold");
  }
  else if ((temp_c >= 10 )&&(temp_c <= 25)){
    Serial.println("Ice Free");
  }
    delay(2000);
  }
  void checkRoadCondition(){
   
  int A = analogRead(analogPin0);
  int B = analogRead(analogPin1);
  int C = analogRead(analogPin2);
 
     // Serial.println(A);
     // Serial.println(B);
     //Serial.println(C);
      //Serial.println();
      //Serial.println();

   
    calibrate(A);
    A = sensorValue;
    //Serial.println(A);
    calibrate(B);
    B = sensorValue;
   // Serial.println(B);
    calibrate(C);
    C = sensorValue;
    //Serial.println(C);

   
    cal_threshold = A+B+C;
   // lastState = cal_threshold;
    //Serial.println(cal_threshold);
   
    if(cal_threshold == 0)
    {
      //Serial.println("Green");
      state = 0;
    }
    else if (cal_threshold == 1)
    {
      // Serial.println("Water on road.");
       state = 1;
    }
    else if (cal_threshold == 2)
    {
      state = 2;
       //Serial.println("Rain");
    }    
    else if (cal_threshold == 3)
    {
      state = 3;
       //Serial.println("Heavy Rain or Flood on road!");
    }
   delay(3000);
  }

  int calibrate(int Value)
  {
    if( (Value > 900) && (Value < 1050))
    {
        sensorValue = 0;
      //  Serial.println("Open Circuit");
    }
    if((Value > 50) && (Value < 860))
    {
     // Serial.println("Close Circuit");
      sensorValue = 1;
    }
    if(Value == 0){sensorValue = 0;}
    if(Value == 1){sensorValue = 1;}
   
  }  