#include "pitches.h"
//scetch->include libraly
//
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};

//
int switchPin = 5;
int buzzerPin = 10;

void setup() {
  pinMode(switchPin, INPUT);
}

void loop() {
  int switchState = digitalRead(switchPin);

  while(switchState == LOW){
    tone(buzzerPin, melody[0], 200);
    delay(100);
    tone(buzzerPin, melody[1], 200);
    delay(100);
    tone(buzzerPin, melody[2], 200);
    delay(100);
    //switchをオンからオフ
    switchState = digitalRead(switchPin);
  }
}
