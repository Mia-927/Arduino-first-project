//サーボモーター制御用のライブラリインポート
#include <Servo.h>
//サーボ　オブジェクト作成
Servo myservo;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // 0~180で1度づつ回転
  for(int angle = 0; angle <= 180; angle++){
    myservo.write(angle);
    delay(30);
    Serial.println(angle);
  }
  delay(1000);
}
