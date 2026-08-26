#include <Servo.h>

// Deklarasi 4 objek Servo
Servo servo1; // Base (Dudukan bawah)
Servo servo2; // Shoulder (Bahu)
Servo servo3; // Elbow (Siku)
Servo servo4; // Gripper (Capit)

// Pin Analog untuk 4 Potensio
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int potPin4 = A3;

// Pin PWM Digital untuk Servo
const int servoPin1 = 11;
const int servoPin2 = 10;
const int servoPin3 = 9;
const int servoPin4 = 6;

void setup() {
  // Menghubungkan pin ke objek servo
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
}

void loop() {
  // 1. Baca nilai potensio (0 - 1023)
  int valPot1 = analogRead(potPin1);
  int valPot2 = analogRead(potPin2);
  int valPot3 = analogRead(potPin3);
  int valPot4 = analogRead(potPin4);

  // 2. Konversi nilai analog ke derajat servo (0 - 180)
  int angle1 = map(valPot1, 0, 1023, 0, 180);
  int angle2 = map(valPot2, 0, 1023, 0, 180);
  int angle3 = map(valPot3, 0, 1023, 0, 180);
  int angle4 = map(valPot4, 0, 1023, 0, 180);

  // 3. Perintahkan servo bergerak ke posisi sudut
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);

  // Jeda singkat untuk stabilitas pergerakan
  delay(15);
}