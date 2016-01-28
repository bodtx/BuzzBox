#define RES 9
#define BUSY 8
#define IO 7
byte i = 0;
byte a = 0;
void setup(void) {

  pinMode(RES, OUTPUT);
  pinMode(IO, OUTPUT);
   pinMode(BUSY, INPUT);
  digitalWrite(RES, HIGH);
  digitalWrite(IO, HIGH);

  Serial.begin(9600);


}

void loop (void) {

  //Serial.println(digitalRead(BUSY));//TODO bloquer la lecture en busy?
  delay(3000);
  //if (Serial.available() != 0)
  //{
   // a = Serial.parseInt();
   // say(a);
   say(0);
   delay(3000);
      say(1);

  //}
}
void say(byte adr)
{
  digitalWrite(RES, LOW);
  delay(5);
  digitalWrite(RES, HIGH);
  delay(17);
  digitalWrite(IO, LOW);
  delay(5);
  for (i = 0; i < 8; i++)
  {
    digitalWrite(IO, HIGH);
    if (bitRead(adr, i))
    {
      delayMicroseconds(600);
      digitalWrite(IO, LOW);
      delayMicroseconds(300);
    }
    else
    {
      delayMicroseconds(300);
      digitalWrite(IO, LOW);
      delayMicroseconds(600);
    }
  }
  digitalWrite(IO, HIGH);
  delay (80);
}
