#include <SPI.h>
#include <MFRC522.h>
String rfid = "";
bool id1 = false;
bool id2 = false;
bool id3 = false;
int successRead;

#define SDA_DIO 10
#define RESET_DIO 9
MFRC522 mfrc522(SDA_DIO, RESET_DIO); 

void setup()
{ 
  Serial.begin(9600);

  SPI.begin(); 
  mfrc522.PCD_Init();
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.println("RFID CARD SETUP");
}

void loop()
{
  do{
    successRead = getID();
  }
  while (!successRead);
  if (rfid == "A7 E3 DE C6")
  {
    id1 = !id1;
    if(id1 == true)
    {
      Serial.println("ANNAMALAI");
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(6,LOW);
      delay(1000);
    }
    else if(id1 == false)
    {
      Serial.println("anna");
      digitalWrite(3,HIGH);
      delay(1000);
      digitalWrite(3,LOW);
      delay(1000);
    }
    
  }

   if (rfid == "F3 EF FE 43")
  {
    id3 = !id3;
    if(id3 == true)
    {
      Serial.println("SANJAY");
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(6,LOW);
      delay(1000);
    }
    else if(id3 == false)
    {
      Serial.println("sanjay");
      digitalWrite(3,HIGH);
      delay(1000);
      digitalWrite(3,LOW);
      delay(1000);
    }
    
  }
  
  if (rfid == "95 1A 53 43")
  {
    id2 = !id2;
   if(id2 == true)
    {
      Serial.println("AJAI");
       digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(6,LOW);
      delay(1000);
      
    }
    else if(id2 == false)
    {
      Serial.println("a1");
       digitalWrite(3,HIGH);
      delay(1000);
      digitalWrite(3,LOW);
      delay(1000);
    } 
  }  
  rfid = "";
  
  
}


int getID() {
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) { 
    return 0;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }
  

  for (int i = 0; i < mfrc522.uid.size; i++) 
  {
    rfid += mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ";
    rfid += String(mfrc522.uid.uidByte[i], HEX); 
  }
  rfid.trim();
  rfid.toUpperCase();
  
  mfrc522.PICC_HaltA();
  return 1;
}
