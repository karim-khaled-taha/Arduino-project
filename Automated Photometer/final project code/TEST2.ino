#include "Stepper.h"
#include <IRremote.h>
#include <LiquidCrystal.h>
float ldrpin = A1;                   
float Vout;                   
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float intensity = 0, I;           // value read from the photodiode
float b = 0.9 , T; 
float A  , C ;
float e ; // لسه عايزين نعرف قيمتها 
int s = 1 ;
int current_posetion;
int sample_num;

/*----- Variables, Pins -----*/
#define STEPS  32  // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution
IRrecv IR(13) ;

/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4

Stepper small_stepper(STEPS, 8, 10, 9, 11);

  
void setup()
{ 
  
    Serial.begin(9600);

    Serial.println("sample      ,Abso         ,TRANS");

   IR.enableIRIn();
   lcd.begin(16, 2);  
   pinMode(ldrpin, INPUT);


   lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("TO START PRRESS ");
      lcd.setCursor(0, 1);
     lcd.print(" THE BUTTOM .... ");

}

void loop()
{

   intensity = analogRead(A1);
  
   I = ((intensity / 1023.0) * 5.0)*10;

    //Serial.print("I= ");
     //Serial.println(I);
    //  T = (I/1.35) *100 ;
     //A = 100-T; A=+-log(T)
    // C=(A/(b*e))  ;  
  
if (IR.decode()) {
    //Serial.println(IR.decodedIRData.decodedRawData);


  { 


    switch(IR.decodedIRData.decodedRawData )

    {

    case 4278239040: // UP button pressed TO take value [0]
     
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("TRANS = ");
     lcd.print(I);
     lcd.setCursor(12, 0);
     lcd.print("%");

      lcd.setCursor(8, 1);
     lcd.print("sample=");
     lcd.print(s);


     break ;

      case 2757476160: // UP button pressed TO START [menu]
      s=1 ;

     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("TRANS = ");
     lcd.print(I);
     lcd.setCursor(12, 0);
     lcd.print("%");

     
     lcd.setCursor(8, 1);
     lcd.print("sample=");
     lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);

     break ;
     case 3977428800: // UP button pressed 
     
       s++ ;

       if (s ==9){
          s=1 ;    
         } 


       small_stepper.setSpeed(500); //Max seems to be 700
       Steps2Take  =  256;  // Rotate CW
       small_stepper.step(Steps2Take);
       delay(1000); 

        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
       Serial.print(s);
       Serial.print(",            ");
       Serial.print(A);
       Serial.print(",            ");
       Serial.println(I);
                      

      

       break;
                          
     case 3944005440: // UP button pressed
         s--;

        if (s == 0){
            s=8 ;
             }

     

     small_stepper.setSpeed(500); //Max seems to be 500
     Steps2Take  =  -256;  // Rotate CW
     small_stepper.step(Steps2Take);
     delay(1000); 
                      
      // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;          

     lcd.setCursor(0, 0);
     lcd.print("WATING.....   ");
     delay(2000);

     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("TRANS = ");
     lcd.print(I);
     lcd.setCursor(12, 0);
     lcd.print("%");
  
     lcd.setCursor(8, 1);
     lcd.print("sample=");
     lcd.print(s);


     Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
    Serial.println(I);
      break;
      

   case 4261527360: //1

        current_posetion =1;
        Steps2Take=(current_posetion-s) ;
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);


       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
                       
            break;              
    case 4244815680: //2
        current_posetion =2;
        Steps2Take=current_posetion-s ;
        Serial.println(Steps2Take);
        small_stepper.setSpeed(500); //Max seems to be 700            
        small_stepper.step(Steps2Take*256);
        s=current_posetion;

        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);


       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;
   case 4228104000: //3
        
        current_posetion =3;
        Steps2Take=current_posetion-s;
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;
   case 4211392320: //4
        
        current_posetion =4;
        Steps2Take=(current_posetion-s) ;
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;
   case 4194680640: //5
        
        current_posetion =5;
        Steps2Take=(current_posetion-s) ;
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;
      case 4177968960: //6
        
        current_posetion =6;
        Steps2Take=(current_posetion-s) ;
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;
      case 4161257280: //7
        
        current_posetion =7;
        Steps2Take=(current_posetion-s) ;
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;
      case 4144545600: //8
        
        current_posetion =8;
        Steps2Take=(current_posetion-s) ;
        small_stepper.setSpeed(500); //Max seems to be 700            
        small_stepper.step(Steps2Take*256);
        s=current_posetion;
        
        // Update the value of I after the motor rotates
       intensity = analogRead(A1);
       I = ((intensity / 1023.0) * 5.0) * 10;
       
        lcd.setCursor(0, 0);
       lcd.print("WATING.....   ");
       delay(2000);


       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("TRANS = ");
       lcd.print(I);
       lcd.setCursor(12, 0);
       lcd.print("%");
  
       lcd.setCursor(8, 1);
       lcd.print("sample=");
       lcd.print(s);

       Serial.print(",             ");
     Serial.print(s);
     Serial.print(",            ");
     Serial.print(A);
     Serial.print(",            ");
     Serial.println(I);
        break;

    
                        
                      
    }
    
    delay(100);
    IR.resume();
      }  

  }

  if (s ==9){
    s=1 ;    
  } else if (s == 0){
    s=8 ;
  }

 delay(100);
}








