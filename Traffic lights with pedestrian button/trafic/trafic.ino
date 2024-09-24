// Define the pins for the traffic lights and pedestrian button
const int carGreenPin = A5;
const int carYellowPin = 9;
const int carRedPin = 10;
const int pedestrianGreenPin = 11;
const int pedestrianRedPin = 12;
const int pedestrianButtonPin = 13;
// Define the pins for the 7-segment display
const int segmentA = 2;
const int segmentB = 3;
const int segmentC = 4;
const int segmentD = 5;
const int segmentE = 6;
const int segmentF = 7;
const int segmentG = 8;

// Define the numbers to be displayed on the 7-segment display
const int digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};
  


void setup() {
  Serial.begin(9600);
  // Set the pins as output or input
  pinMode(carGreenPin, OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carRedPin, OUTPUT);
  pinMode(pedestrianGreenPin, OUTPUT);
  pinMode(pedestrianRedPin, OUTPUT);
  pinMode(pedestrianButtonPin, INPUT);
  // Set the pins for the segments as outputs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  

  // Set the initial state of the traffic lights
  digitalWrite(carGreenPin, HIGH);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carRedPin, LOW);
  digitalWrite(pedestrianGreenPin, LOW);
  digitalWrite(pedestrianRedPin, HIGH);

}

void loop() {
  // Check if the pedestrian button is pressed
  if (digitalRead(pedestrianButtonPin) == HIGH) {
    // Pedestrian wants to cross
    digitalWrite(carGreenPin, LOW);
    digitalWrite(carYellowPin, HIGH);
    digitalWrite(carRedPin, LOW);
    digitalWrite(pedestrianGreenPin, LOW);
    digitalWrite(pedestrianRedPin, HIGH);
    // Display "don't cross" on the monitor
      Serial.println("don't cross");
    
    for (int i = 9; i >= 0; i--) {
      digitalWrite(carYellowPin, HIGH);
      delay(500);
    //digitalWrite(carYellowPin, LOW); 

    digitalWrite(segmentA, digits[i][0]);
    digitalWrite(segmentB, digits[i][1]);
    digitalWrite(segmentC, digits[i][2]);
    digitalWrite(segmentD, digits[i][3]);
    digitalWrite(segmentE, digits[i][4]);
    digitalWrite(segmentF, digits[i][5]);
    digitalWrite(segmentG, digits[i][6]);
    delay(500); 
    }
    
    
    digitalWrite(carGreenPin, LOW);
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carRedPin, HIGH);
    digitalWrite(pedestrianGreenPin, HIGH);
    digitalWrite(pedestrianRedPin, LOW);
    // Display "cross" on the monitor
          Serial.println("cross");
    // Wait 15 seconds
    delay(15000);
    // Pedestrian has finished crossing
     // Wait 5 seconds
    for (int i = 5; i >= 0; i--) {
    digitalWrite(segmentA, digits[i][0]);
    digitalWrite(segmentB, digits[i][1]);
    digitalWrite(segmentC, digits[i][2]);
    digitalWrite(segmentD, digits[i][3]);
    digitalWrite(segmentE, digits[i][4]);
    digitalWrite(segmentF, digits[i][5]);
    digitalWrite(segmentG, digits[i][6]);
          delay(1000); 

    }
        Serial.println("don't cross");
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carRedPin, LOW);
    digitalWrite(pedestrianRedPin, LOW);
    digitalWrite(carYellowPin, HIGH);
    digitalWrite(pedestrianRedPin, HIGH);
  } else {
    // No pedestrian wants to cross
    digitalWrite(carGreenPin, HIGH);
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carRedPin, LOW);
    digitalWrite(pedestrianGreenPin, LOW);
    digitalWrite(pedestrianRedPin, HIGH);
  }
}













































 