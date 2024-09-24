 int motor1ForwardPin = 6;  // Replace with actual pin numbers
 int motor1BackwardPin = 9;
 int motor2ForwardPin = 10;
 int motor2BackwardPin = 11;

int fd_Led_R = 9;
int fd_Led_L = 9;

int bk_Led_R = 10;
int bk_Led_L = 10;

int Y_Led_1 = 12;
int Y_Led_2 = 12;
int Y_Led_3 = 12;
int Y_Led_4 = 12;

int hornPin = 7;    

bool condition = false; // Variable to control LED toggle





void setup() {
  Serial.begin(9600);

  pinMode(fd_Led_R, OUTPUT);
  pinMode(fd_Led_L, OUTPUT);
  pinMode(bk_Led_R, OUTPUT);
  pinMode(bk_Led_L, OUTPUT);
  pinMode(Y_Led_1, OUTPUT);
  pinMode(Y_Led_2, OUTPUT);
  pinMode(Y_Led_3, OUTPUT);
  pinMode(Y_Led_4, OUTPUT);
  pinMode(motor1ForwardPin, OUTPUT);
  pinMode(motor1BackwardPin, OUTPUT);
  pinMode(motor2ForwardPin, OUTPUT);
  pinMode(motor2BackwardPin, OUTPUT);
  pinMode(hornPin, OUTPUT);

  stopMotors(); // Stop motors initially
}

void moveForward() {
  digitalWrite(motor1ForwardPin, HIGH);
  digitalWrite(motor1BackwardPin, LOW);
  digitalWrite(motor1BackwardPin, HIGH);
  digitalWrite(motor2BackwardPin, LOW);
}

void moveBackward() {
  digitalWrite(motor1ForwardPin, LOW);
  digitalWrite(motor1BackwardPin, HIGH);
  digitalWrite(motor2ForwardPin, LOW);
  digitalWrite(motor2BackwardPin, HIGH);
}

void moveForwardLeft() {
  analogWrite(motor1ForwardPin, 255);
  analogWrite(motor1BackwardPin, 0);
  analogWrite(motor2ForwardPin, 100);
  analogWrite(motor2BackwardPin, 0);
}

void moveForwardRight() {
  analogWrite(motor1ForwardPin, 100);
  analogWrite(motor1BackwardPin, 0);
  analogWrite(motor2ForwardPin, 255);
  analogWrite(motor2BackwardPin, 0);
}

void moveBackwardLeft() {
  analogWrite(motor1ForwardPin, 0);
  analogWrite(motor1BackwardPin, 255);
  analogWrite(motor2ForwardPin, 0);
  analogWrite(motor2BackwardPin, 100);
}

void moveBackwardRight() {
  analogWrite(motor1ForwardPin, 0);
  analogWrite(motor1BackwardPin, 100);
  analogWrite(motor2ForwardPin, 0);
  analogWrite(motor2BackwardPin, 255);
}

void moveLeft() {
  digitalWrite(motor1ForwardPin, LOW);
  digitalWrite(motor1BackwardPin, HIGH);
  digitalWrite(motor2ForwardPin, LOW);
  digitalWrite(motor2BackwardPin, LOW);
}

void moveRight() {
  digitalWrite(motor1ForwardPin, HIGH);
  digitalWrite(motor1BackwardPin, LOW);
  digitalWrite(motor2ForwardPin, LOW);
  digitalWrite(motor2BackwardPin, HIGH);
}

void stopMotors() {
  digitalWrite(motor1ForwardPin, LOW);
  digitalWrite(motor1BackwardPin, LOW);
  digitalWrite(motor2ForwardPin, LOW);
  digitalWrite(motor2BackwardPin, LOW);
}
void lightfd() {
  digitalWrite(fd_Led_R, HIGH);
  digitalWrite(fd_Led_L, HIGH);
  digitalWrite(bk_Led_R, LOW);
  digitalWrite(bk_Led_L, LOW);
}
void lightbk() {
  digitalWrite(fd_Led_R, LOW);
  digitalWrite(fd_Led_L, LOW);
  digitalWrite(bk_Led_R, HIGH);
  digitalWrite(bk_Led_L, HIGH);
}
void lightfd_off() {
  digitalWrite(fd_Led_R, LOW);
  digitalWrite(fd_Led_L, LOW);
  digitalWrite(bk_Led_R, LOW);
  digitalWrite(bk_Led_L, LOW);
}
void lightbk_off() {
  digitalWrite(fd_Led_R, LOW);
  digitalWrite(fd_Led_L, LOW);
  digitalWrite(bk_Led_R, LOW);
  digitalWrite(bk_Led_L, LOW);
}
void horn_on() {
  tone(hornPin, 4000);
}
void horn_oFF() {
  noTone(hornPin);
}
void loop() {
  
  if (Serial.available() > 0) {
    char characters = Serial.read();
    
    switch (characters) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'G':
        moveForwardLeft();
        break;
      case 'I':
        moveForwardRight();
        break;
      case 'H':
        moveBackwardLeft();
        break;
      case 'J':
        moveBackwardRight();
        break;
      case 'L':
        moveLeft();
        break;
      case 'R':
        moveRight();
        break;
      case 'S':
        stopMotors();
        break;
      case 'W':
        lightfd();
        break;
      case 'w':
        lightfd_off();
        break;
      case 'U':
        lightbk();
        break;
      case 'u':
        lightbk_off();
        break;
      case 'X':
        condition = !condition; // Toggle the LED state
        break;
      case 'x':
        condition = false; // Turn off the LED and break the loop
        break;
      default:
        break;
       case 'V':
        horn_on();
        break;
      case 'v':
        horn_oFF();
        break;  
    
    }
  }
   if (condition) {
    digitalWrite(Y_Led_1, HIGH);
    digitalWrite(Y_Led_2, HIGH);
    digitalWrite(Y_Led_3, HIGH);
    digitalWrite(Y_Led_4, HIGH);
     delay(500); // Wait for 0.5 seconds
    digitalWrite(Y_Led_1, LOW);
    digitalWrite(Y_Led_2, LOW);
    digitalWrite(Y_Led_3, LOW);
    digitalWrite(Y_Led_4, LOW);   
     delay(500); // Wait for 0.5 seconds
  }
}
