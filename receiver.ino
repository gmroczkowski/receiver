/*
  Simple example for receiving
  http://code.google.com/p/rc-switch/
*/

//#include <SPI.h>

#define pin_RF 2
#define pin_LED 13

String ramka = "";
unsigned long czas0 = 0;
unsigned long czas1 = 0;
int czasLOW[100];
int czasHIGH[100];
int  czas2[100];
int i = 0;
boolean Show = false;

void setup() {
  Serial.begin(115200);
  pinMode(pin_LED, OUTPUT);
  pinMode(pin_RF, INPUT);
  Serial.print("Starting...\n");
}

void loop() {
  czas1 = micros();
  while (digitalRead(pin_RF) == HIGH);
  czasHIGH[0] = (int)(micros() - czas1);
  if ((czasHIGH[0] > 4700) && (czasHIGH[0] < 5000))
  {
    czas1 = micros();
    while (digitalRead(pin_RF) == LOW);
    czasLOW[0] = (int)(micros() - czas1);
    if ((czasLOW[0] > 1500) && (czasLOW[0] < 1600))
    {
      for (i = 1; i < 41; i++)
      {
        czas1 = micros();
        while (digitalRead(pin_RF) == HIGH);
        czasHIGH[i] = (int)(micros() - czas1);
        czas1 = micros();
        while (digitalRead(pin_RF) == LOW);
        czasLOW[i] = (int)(micros() - czas1);
      }
      Show = true;
    }
  }

  if (Show)
  {
    for (i = 0; i < 41; i++)
    {
      if (czasHIGH[i] + czasLOW[i] > 6000)
      {
        Serial.print("S");
      } else
      {
        if (czasHIGH[i] > czasLOW[i])
        {
          Serial.print("1 ");
        } else Serial.print("0 ");
      }
      if (i==28) Serial.print ("  Nr rol: ");
      if (i==32) Serial.print (" Roz. x2: ");
    }
    Serial.print("\n");
    
      for (i = 0; i < 100; i++)
      {
      Serial.print((String)czasLOW[i]);
      Serial.print(";");
      }
      Serial.print("\n");
      Serial.print("\n");

      Serial.println((String)czas2[0] + " " + (String)czas2[1] + " " + (String)czas2[2] + " " + (String)czas2[3] + " " + (String)czas2[4] + " " + (String)czas2[5] + " " + (String)czas2[6] + " " + (String)czas2[7] + " " + (String)czas2[8] + " " + (String)czas2[9] + " " + (String)czas2[10] + " " + (String)czas2[11] + " " + (String)czas2[12] + " " + (String)czas2[13] + " " + (String)czas2[14] + " " + (String)czas2[15] + " " + (String)czas2[16] + " " + (String)czas2[17] + " " + (String)czas2[18] + " " + (String)czas2[19] + " " + (String)czas2[20] + " " + (String)czas2[21] + " " + (String)czas2[22] + " " + (String)czas2[23] + " " + (String)czas2[24] + " " + (String)czas2[25] + " " + (String)czas2[26] + " " + (String)czas2[27] + " " + (String)czas2[28] + " " + (String)czas2[29] + " " + (String)czas2[30] + " " + (String)czas2[31] + " " + (String)czas2[32] + " " + (String)czas2[33] + " " + (String)czas2[34] + " " + (String)czas2[35] + " " + (String)czas2[36] + " " + (String)czas2[37] + " " + (String)czas2[38] + " " + (String)czas2[39] + " ");
    
    Show = false;
  }
  /*
    if (ramka!="")
    {
      Serial.print(ramka);
      Serial.print("\n");
      ramka="";
    }
    //Serial.print((String)czas2[0]+" "+(String)czas2[1]+" "+(String)czas2[2]+" "+(String)czas2[3]+" "+(String)czas2[4]+" "+(String)czas2[5]+" "+(String)czas2[6]+" "+(String)czas2[7]+" "+(String)czas2[8]+" "+(String)czas2[9]+" "+(String)czas2[10]+" "+(String)czas2[11]+" "+(String)czas2[12]+" "+(String)czas2[13]+" "+(String)czas2[14]+" "+(String)czas2[15]+" "+(String)czas2[16]+" "+(String)czas2[17]+" "+(String)czas2[18]+" "+(String)czas2[19]+" "+(String)czas2[20]+" "+(String)czas2[21]+" "+(String)czas2[22]+" "+(String)czas2[23]+" "+(String)czas2[24]+" "+(String)czas2[25]+" "+(String)czas2[26]+" "+(String)czas2[27]+" "+(String)czas2[28]+" "+(String)czas2[29]+" "+(String)czas2[30]+" "+(String)czas2[31]+" "+(String)czas2[32]+" "+(String)czas2[33]+" "+(String)czas2[34]+" "+(String)czas2[35]+" "+(String)czas2[36]+" "+(String)czas2[37]+" "+(String)czas2[38]+" "+(String)czas2[39]+" ");


      czas1 = micros();
      while (digitalRead(pin_RF) == LOW)
      {

      }
      czas2 = czas1 - micros();
      Serial.println((String)czas2);

      while (micros()-time
      delayMicroseconds(4760);
      if (!digitalRead(pin_RF))
      {
      delayMicroseconds(1520);
      for (int i = 0; i < 40; i++)
      {
        //digitalWrite(13, HIGH);
        ramka += (String)digitalRead(pin_RF);
        delayMicroseconds(1080);
        //digitalWrite(13, LOW);
      }
      }
      Serial.println(ramka);
      ramka = "";
  */


  //delay(500);
  //Serial.print(".");
}
