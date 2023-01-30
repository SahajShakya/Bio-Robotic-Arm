#include <MIDI.h>

int tem;
int sig;
int outpin = 13;
int angpin = A0;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(115200);
  Serial.begin(9600);
  
  pinMode(outpin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tem = analogRead(A0);
  float sig = tem*(5.0/1023.0);
  //float sig = map(tem, 0, 1023, 0, 5000);
  Serial.println(sig);
  analogWrite(angpin, sig);
  if (sig >= 1){
    digitalWrite(outpin, HIGH);   
  }
  else{
    digitalWrite(outpin, LOW);
  }
  delay(10);
}
