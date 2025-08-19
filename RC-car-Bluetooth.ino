
const int IN1 = 11;  
const int IN2 = 10;  
const int IN3 = 9;   
const int IN4 = 8;   

void setup() {
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  for Bluetooth
  Serial.begin(9600);

  allStop();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch(command) {
      case 'F': 
        motor1Forward();
        motor2Forward();
        break;
      case 'B': 
        motor1Backward();
        motor2Backward();
        break;
      case 'L':
        motor1Backward(); 
        motor2Forward();   
        break;
      case 'R':
        motor1Forward();   
        motor2Backward();  
        break;
      case 'S':
        allStop();
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
