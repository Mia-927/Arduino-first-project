//アナログ入力設定
const int analogPin = 0;

const float B = 3950.0;//サーミスタのB定数
const float RO = 3950.0;//サーミスタの25度の抵抗値
const float Rd = 3950.0;//検知抵抗の抵抗値
const float Tk = 273.15;//０C = 273.15K

void setup() {
  // put your setup code here, to run once:
  //シリアルモニター用
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //アナログ値を読む　
  float readValue = analogRead(analogPin);
  //Rtを計算する
  float Rt = Rd * readValue / (1023 - readValue);
  //Tを計算（K)
  float Tber = 1/B* log(Rt/RO) + 1 / (Tk + 25);
  float T = 1/Tber;
  //ケルビンからCに
  float Tdeg = T - Tk;
  //シリアルモニターに表示
  Serial.println(Tdeg);
  delay(200);//0.2s待機
}
