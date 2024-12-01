#include<ESP32Servo.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
char com = 'S';


Servo s1;
Servo s2;

int val_1=90;
int val_2=90;

void setup(){
  SerialBT.begin("Hand");
  Serial.begin(115200);
  pinMode(g, OUTPUT);
  pinMode(u, OUTPUT);
  s1.attach(27);
  s2.attach(14);
} 


void loop() {
 
  if (SerialBT.available() > 0) {
    com = SerialBT.read();
    Serial.println(com);
  }
  switch (com) {
    // case 'F':
    //   servo_1up();
    //   break;
    // case 'B':
    //   servo_1down();
    //   break;
    // case 'L':
    //    servo_2up();
    //   break;
    // case 'R':
    //    servo_2down();
    //   break;
    case 'u':
      grip();
      break;
    case 'd':
      ungrip();
      break;
    case 'S':
      stopMotor();
      break;
    default:
      stopMotor();
      break;
  }
}

void stopMotor(){
 digitalWrite(g,LOW);
 digitalWrite(u,LOW);
}

void servo_1up() {
  val_1 = val_1 + 1;
  if (val_1 >= 170) {
    val_1 = 170;
  }
  if (val_1 <= 10) {
    val_1 = 10;
  }
  s1.write(val_1);

}
//front 10 to 110
//90 to 0

void servo_1down() {
  val_1 = val_1 - 1;
  
  if (val_1 >= 90) {
    val_1 = 90;
  }
  if (val_1 <= 5) {
    val_1 = 5;
  }

 s1.write(val_1);
}


void servo_2up() {
  val_2 = val_2 + 1;
  if (val_2 >= 110) {
    val_2 = 110;
  }
  if (val_2 <= 10) {
    val_2 = 10;
  }
  s2.write(val_2);
  delay(10);
}

void servo_2down() {
  val_2 = val_2 - 1;
  
  if (val_2 >= 110) {
    val_2 = 110;
  }
  if (val_2 <= 10) {
    val_2 = 10;
  }
  delay(30);
  s2.write(val_2);
}


void grip(){
  digitalWrite(g,HIGH);
  digitalWrite(u,LOW);

}

void ungrip(){
  digitalWrite(u,HIGH);
  digitalWrite(g,LOW);

}