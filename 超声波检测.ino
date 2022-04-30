int Trig=13;
int Echo=12;
int Led=11;
float dist;
int ball_passed=false;
void setup() {
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);

}

void loop() {
  digitalWrite(Trig,LOW);
  delayMicroseconds(8);
  digitalWrite(Echo, HIGH);
  // 维持10毫秒高电平用来产生一个脉冲
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  // 读取脉冲的宽度并换算成距离
  dist = pulseIn(Echo, HIGH) / 58.00;
  Serial.print("Distance:");
  Serial.print(dist);
  Serial.println("cm");
  if (dist<=6) {
    ball_passed=true;
  }
  
  if (ball_passed==true)
  {
    digitalWrite(Led,HIGH);
    delay(1000);
    digitalWrite(Led,LOW);
    ball_passed=false;

  }
  
}
