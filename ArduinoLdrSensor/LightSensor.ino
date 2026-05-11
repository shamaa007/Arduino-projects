 // Light Sensor using LDR and Arduino

int ldrPin = A0;      // LDR connected to analog pin A0
int ledPin = 13;      // LED connected to pin 13

int ldrValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  ldrValue = analogRead(ldrPin);   // Read LDR value

  Serial.println(ldrValue);        // Print value to Serial Monitor

  // If it becomes dark, turn ON LED
  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}