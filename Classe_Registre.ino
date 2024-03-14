#include "Register.h"

Register myRegis(5, 6, 7, 1);


void setup() {
  Serial.begin(9600);
  myRegis.SetRegPin();
  myRegis.initOut();
}

void loop() {
  for (int lead = 0; lead <= 500; lead+=2)
  {
    Serial.print("Ecart  = ");
    Serial.println(lead);
    for (int i = 0; i < 8; i++)
    {
      myRegis.Set(i);
      delay(lead);
    }
    for (int i = 0; i < 8; i++) 
    {
      myRegis.Reset(7-i);
      delay(lead);
    }
  }
}
