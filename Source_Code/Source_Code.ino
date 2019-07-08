/* LPG Leakage Detector With MQ - 6 Sensor

   GitHub URL - https://github.com/narayanvyas/LPG-Gas-Leakage-Detector-With-MQ-6

   Components
   ----------
    - Arduino Uno R3
    - MQ-6 Sensor
    - Two LEDs
    - Two 220 Ohm Resistors
    - A Buzzer
    - PCB
    - Wires

   Connections
   -----------
        Break out          |     Arduino Uno
   --------------------------------------------
        MQ6 VCC            |        5V
        MQ6 GND            |        GND
        MQ6 Analog Pin     |        A5
        Buzzer GND         |        GND
        Buzzer OUT         |        2
        LED 1 OUT          |        3
        LED 2 OUT          |        4

     Also connect LEDs two 220 Ohm Resistors.

         ----/\/\/\/\----(LED |)----GND
*/

int sensorValue;
int buzzerPin = 2;
int greenLED = 3;
int redLED = 4;
int heatingTimer = 20;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.println("Sensor Warming Up, Please Wait For 10 Seconds...");
  for(int i=0; i<20; i++) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    delay(500);
  }
  digitalWrite(greenLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void loop() {
  sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  if(sensorValue>300) {   // Sensitivity to gas
    tone(buzzerPin, 1000);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else {
    noTone(buzzerPin);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  delay(1000);
}
