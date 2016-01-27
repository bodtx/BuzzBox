/*

This program cycles through the first eight files loaded onto a WT588D-16P Sound Module

The pins labeled on the data sheet as CLK, DI, DO, CS, REST are for programming
the module via the external USB programmer.

In the Waytronic VoiceChip beta software, the settings are configured as "Control Mode: Three Line Mode, and Busy Mode: LOW"


*/

#define WT588D_RST 7 //Module pin "REST" or pin # 1
#define WT588D_CS 6 //Module pin "P02" or pin # 11
#define WT588D_SCL 9 //Module pin "P03" or pin # 10
#define WT588D_SDA 8 //Module pin "P01" or pin # 9

#define WT588D_BUSY 10 //Module pin "LED/BUSY" or pin # 15

byte file_count = 1;

void setup() {
  
  Serial.begin(9600); 

  pinMode(WT588D_RST, OUTPUT); 
  pinMode(WT588D_CS, OUTPUT);
  pinMode(WT588D_SCL, OUTPUT);
  pinMode(WT588D_SDA, OUTPUT);
  
  pinMode(WT588D_BUSY, INPUT); 

  digitalWrite(WT588D_CS, HIGH);
  digitalWrite(WT588D_RST, HIGH);
  digitalWrite(WT588D_SCL, HIGH);

}


void loop()
{
Serial.println(file_count);


//WT588D_Send_Command(0);



//WT588D_Send_Command(0);

 WT588D_Send_Command(1);
delay (5000);
//delay (5000);
/*  WT588D_Send_Command(file_count);

  file_count++;

  if(file_count == 8) file_count = 0;

  delay(50); //give the module time to start playing

Serial.println("on est busy");
  while(digitalRead(WT588D_BUSY) == 0) { }
Serial.println("on est plus busy");
  delay(200);
*/
}


/*void WT588D_Send_Command(byte addr) {
   digitalWrite(WT588D_SDA, LOW);
   delay(5);

   for(int i = 0; i < 8; i++)  {
       digitalWrite(WT588D_SDA, HIGH);
       if(bitRead(addr, i)) {
           delayMicroseconds(600);
           digitalWrite(WT588D_SDA, LOW);
           delayMicroseconds(200);
       } else {
           delayMicroseconds(200);
           digitalWrite(WT588D_SDA, LOW);
           delayMicroseconds(600);
       }
   }

   digitalWrite(WT588D_SDA, HIGH);
   delay(100);
}*/

void WT588D_Send_Command(unsigned char addr) {

  unsigned char i;

  digitalWrite(WT588D_CS, LOW);

  delay(5); //delay per device specifications

  for( i = 0; i < 8; i++)  {   
    digitalWrite(WT588D_SCL, LOW);   
    if(bitRead(addr, i))digitalWrite(WT588D_SDA, HIGH);
    else digitalWrite(WT588D_SDA, LOW);         
    delay(2);  //delay per device specifications   
    digitalWrite(WT588D_SCL, HIGH);   
    delay(2);  //delay per device specifications
  } //end for

  digitalWrite(WT588D_CS, HIGH);

} //end WT588D_Send_Command

