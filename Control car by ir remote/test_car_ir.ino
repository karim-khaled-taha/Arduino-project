#include <IRremote.h>

IRrecv IR(2);
const int ldrPin = A0;  

#define m1 9
#define horn 12
int Y_Led_1 = 3;
int Y_Led_2 = 4;
int Y_Led_3 = 5;
int Y_Led_4 = 11;
int m1_state=0;
int horn_state=0;
bool condition = false; // Variable to control LED toggle






void setup()
{
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(ldrPin, INPUT);    
  pinMode(m1,OUTPUT);
  pinMode(horn,OUTPUT);
  pinMode(Y_Led_1, OUTPUT);
  pinMode(Y_Led_2, OUTPUT);
  pinMode(Y_Led_3, OUTPUT);
  pinMode(Y_Led_4, OUTPUT);

}

void loop()
{
  
  if (IR.decode()) {
    Serial.println(IR.decodedIRData.decodedRawData);

    if (IR.decodedIRData.decodedRawData == 3977428800 && m1_state==0 ) {
      // Turn on LEDR when the corresponding button is pressed
      digitalWrite(m1, HIGH);
      m1_state = 1 ;
      //IR.decodedIRData.decodedRawData = 0 ;
    } else if (IR.decodedIRData.decodedRawData == 3944005440 && horn_state == 0 ) {
      // Turn on LEDG when the corresponding button is pressed
      digitalWrite(horn, HIGH);
      horn_state = 1 ;
      //IR.decodedIRData.decodedRawData = 0 ;
    }  else if (IR.decodedIRData.decodedRawData == 4261527360  ) {
       condition = !condition; // Toggle the LED state
       //IR.decodedIRData.decodedRawData = 0 ;
    } else {
      // Additional conditions to turn off each LED individually
      if (digitalRead(m1) == HIGH && IR.decodedIRData.decodedRawData == 3977428800 && m1_state ==1) {
        digitalWrite(m1, LOW);
        m1_state = 0 ;
       //IR.decodedIRData.decodedRawData = 0 ;

      } if (digitalRead(horn) == HIGH && IR.decodedIRData.decodedRawData ==3944005440 && horn_state == 1) {
        digitalWrite(horn, LOW);
        horn_state = 1 ;
       //IR.decodedIRData.decodedRawData = 0 ;
    
      }
       if (IR.decodedIRData.decodedRawData == 4261527360  ) {
       condition = false; // Turn off the LED and break the loop
       //IR.decodedIRData.decodedRawData = 0 ;
   
    }
    }
    delay(1500);
    IR.resume();
  
  }
   if (condition) {
    digitalWrite(Y_Led_1, HIGH);
    digitalWrite(Y_Led_2, HIGH);
    digitalWrite(Y_Led_3, HIGH);
    digitalWrite(Y_Led_4, HIGH);
    digitalWrite(horn, HIGH);

     delay(500); // Wait for 0.5 seconds
    digitalWrite(Y_Led_1, LOW);
    digitalWrite(Y_Led_2, LOW);
    digitalWrite(Y_Led_3, LOW);
    digitalWrite(Y_Led_4, LOW);
     digitalWrite(horn, LOW);   
     delay(500); // Wait for 0.5 seconds
  }
  }

