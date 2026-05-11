 #include <Servo.h>

Servo radarServo;

// HC-SR04 pins
const int trigPin = 8;
const int echoPin = 9;

// Buzzer and LED
const int buzzer = 7;
const int led = 13;

// Servo pin
const int servoPin = 10;

long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  radarServo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {

  // Sweep from 0 to 180
  for (int angle = 0; angle <= 180; angle++) {

    radarServo.write(angle);

    distance = getDistance();

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  Distance: ");
    Serial.println(distance);

    // Object detection
    if (distance > 0 && distance < 30) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
    }
    else {
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
    }

    delay(30);
  }

  // Sweep back from 180 to 0
  for (int angle = 180; angle >= 0; angle--) {

    radarServo.write(angle);

    distance = getDistance();

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  Distance: ");
    Serial.println(distance);

    if (distance > 0 && distance < 20) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
    }
    else {
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
    }

    delay(30);
  }
}


// Function to measure distance
int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}