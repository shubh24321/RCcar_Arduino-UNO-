// Motor control pins
const int IN1 = 11;  // Motor 1 Forward
const int IN2 = 10;  // Motor 1 Backward
const int IN3 = 9;   // Motor 2 Forward
const int IN4 = 8;   // Motor 2 Backward

void setup() {
  // Initialize motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Initialize serial communication for Bluetooth
  Serial.begin(9600);
  
  // Stop all motors initially
  allStop();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch(command) {
      case 'F': // Forward (both motors forward)
        motor1Forward();
        motor2Forward();
        break;
      case 'B': // Backward (both motors backward)
        motor1Backward();
        motor2Backward();
        break;
      case 'L': // Left turn (right motor forward, left motor backward)
        motor1Backward();  // Left motor backward
        motor2Forward();   // Right motor forward
        break;
      case 'R': // Right turn (left motor forward, right motor backward)
        motor1Forward();   // Left motor forward
        motor2Backward();  // Right motor backward
        break;
      case 'S': // Stop
        allStop();
        break;
      // Individual motor controls
      case '1': // Motor 1 forward
        motor1Forward();
        motor2Stop();
        break;
      case '2': // Motor 1 backward
        motor1Backward();
        motor2Stop();
        break;
      case '3': // Motor 1 stop
        motor1Stop();
        break;
      case '4': // Motor 2 forward
        motor2Forward();
        motor1Stop();
        break;
      case '5': // Motor 2 backward
        motor2Backward();
        motor1Stop();
        break;
      case '6': // Motor 2 stop
        motor2Stop();
        break;
    }
  }
}

// Motor control functions
void motor1Forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void motor1Backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void motor1Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor2Forward() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motor2Backward() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void motor2Stop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void allStop() {
  motor1Stop();
  motor2Stop();
}