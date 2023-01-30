#include <Servo.h>

#define in_port A0
#define out_port 9
#define led 13

Servo myservo;

int emg_signal;
int mapped_signal;
int servo_value;

void setup() {
  pinMode(in_port, INPUT);
  pinMode(out_port, OUTPUT);
  pinMode(led, OUTPUT);

  myservo.attach(out_port);

  Serial.begin(9600);
}

void loop() {
  emg_signal = analogRead(in_port);
  mapped_signal = map(emg_signal, 0, 1023, 0 ,5000);
  Serial.println(mapped_signal);

  if(mapped_signal >= 80){
    digitalWrite(led, HIGH);
    myservo.write(110);
  }
  else{
    digitalWrite(led, LOW);
    myservo.write(0);
  }
  
  //servo_value = map(mapped_signal, 0, 1000, 0, 150);
  //myservo.write(servo_value);
}
