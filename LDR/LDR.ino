int ldrPin = A0;
int ledPin = 13;
int ldrValue;
int lastValue = -1;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);

  if (ldrValue > 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (ldrValue != lastValue) {
    Serial.print("LDR Value: ");
    Serial.print(ldrValue);
    Serial.println(ldrValue > 500 ? "  | LED: ON" : "  | LED: OFF");
    lastValue = ldrValue;
  }

  delay(200);
}