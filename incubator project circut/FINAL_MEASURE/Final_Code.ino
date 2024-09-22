#include <LiquidCrystal.h>  
bool stopLoop = false; // Variable to control the while loop

int sencpin = A0;
int fan = 6; 
int led = 13; 
int led_error=A1;
int buzzer_pin=A2;
float temp;
int pintempinc=10;
int pintempdec=7;
int pintempset=9;
int stendpin=8;
int stendcount=0;
int setcount=0;
int tempset=0;
int tempneed=0;
int tempreq=25;
int ldrPin=A5;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
lcd.begin(16,2);
pinMode(fan, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led_error, OUTPUT);
pinMode(buzzer_pin, OUTPUT);
pinMode(pintempinc, INPUT);
pinMode(pintempdec, INPUT);
pinMode(pintempset, INPUT);
pinMode(stendpin, INPUT);
pinMode(ldrPin, INPUT);

Serial.begin(9600);
}


void loop() {
   temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
 
   int ldrValue = analogRead(ldrPin);
  //Serial.print("LDR Value: ");
  Serial.println(ldrValue);
   // delay(100);

  if (ldrValue < 1000) {
    lcd.clear();
    lcd.print("ERROR !");
     lcd.setCursor(1,2);
  lcd.print("door is opean"); 
    digitalWrite(fan, LOW);
    digitalWrite(led, LOW);
    tone(buzzer_pin,4000);
    
        delay(100);
      digitalWrite(led_error,HIGH );
      delay(50);
       digitalWrite(led_error,LOW );
      delay(50);

    
    
    
  }
    

    if (ldrValue==1022 ){
    
    noTone(buzzer_pin);
    digitalWrite(led_error,LOW );
      
  
  
if (digitalRead(stendpin)==HIGH) {
stendcount=stendcount+1;
Serial.print( "stendcount" );
Serial.println( stendcount );
  delay(150);
}


if ((stendcount%2)==1) { //end action

  if(tempneed < temp) {
 float fan_speed = map(temp, 0, 1023, 0, 255);    
analogWrite(fan, fan_speed);
digitalWrite(led, LOW);
digitalWrite(fan, HIGH);

  
}
  else if (tempneed==temp){
   digitalWrite(led, LOW);
    digitalWrite(fan, LOW);  

  }

if(tempneed > temp){
  digitalWrite(fan, LOW);  
  digitalWrite(led, HIGH); 
}
      delay(100);


}

else if ((stendcount%2)==0){
  digitalWrite(fan, LOW);
  digitalWrite(led, LOW);
     delay(100);



if (digitalRead(pintempset)==HIGH) {
setcount=setcount+1;
Serial.print( "setcount" );
Serial.println( setcount );
    delay(500);


}

if ((setcount%2)==1) {
   tempneed=tempset;
   Serial.print( "tempneed" );
 Serial.println( tempneed );
    delay(100);


 }
 else if ((setcount%2)==0) {
if (digitalRead(pintempinc)==HIGH){
 tempreq=tempreq+1;
 
  lcd.setCursor(9,2);
  lcd.print(tempreq); 
  lcd.print(" C ");
    delay(100);


}

if (digitalRead(pintempdec)==HIGH){
 tempreq=tempreq-1;
 
  
  lcd.setCursor(9,2);
  lcd.print(tempreq); 
  lcd.print(" C ");
    delay(100);
 
}
   tempset=tempreq;
 }
}
          lcd.clear();

      lcd.setCursor(0,0);
  lcd.print("temp"); 
  lcd.setCursor(6,0);
  lcd.print(temp); 
  lcd.print(" C ");
  
   lcd.setCursor(0,1);
lcd.print("tempreq"); 
    lcd.setCursor(9,2);
  lcd.print(tempreq); 
    lcd.print(" C ");
    }
 
    
  

    delay(1000); 

}
