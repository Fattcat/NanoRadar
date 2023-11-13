#define TRIGGER_PIN1 2
#define ECHO_PIN1 3
#define TRIGGER_PIN2 4
#define ECHO_PIN2 5
#define TRIGGER_PIN3 6
#define ECHO_PIN3 7

// Connection
// Radar - Arduino Nano 
// VCC - 5V
// GND - GND
// (Radar Number 1Pin) ECHO - D3
// (Radar Number 1Pin) TRIG - D2
//

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIGGER_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIGGER_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
}

void loop() {
  long duration1, duration2, duration3;
  int distance1, distance2, distance3;
  
  // Senzor 1
  digitalWrite(TRIGGER_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = duration1 * 0.034 / 2;  // Výpočet vzdialenosti v cm

  // Senzor 2
  digitalWrite(TRIGGER_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  distance2 = duration2 * 0.034 / 2;  // Výpočet vzdialenosti v cm

  // Senzor 3
  digitalWrite(TRIGGER_PIN3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN3, LOW);
  duration3 = pulseIn(ECHO_PIN3, HIGH);
  distance3 = duration3 * 0.034 / 2;  // Výpočet vzdialenosti v cm
  
  // Zobrazenie vzdialeností v sériovom monitore
  Serial.print("Senzor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Senzor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  Serial.print("Senzor 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
  
  delay(1000);  // Aktualizujte výstup raz za sekundu
}
