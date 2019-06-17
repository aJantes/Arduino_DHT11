#include "cjt_DHT11.h"
#include <Arduino.h>

cjt_DHT11 dht11(26);

void setup()
{
  Serial.begin(9600);
  Serial.printf("OK!");
  Serial.println();
}

void loop()
{
  dht11.cjt_DHT11_Read();
  
  Serial.printf("temp:");
  Serial.print(dht11.dht11_temp);
  Serial.println();

  Serial.printf("humt:");
  Serial.print(dht11.dht11_humt);
  Serial.println();

  delay(1300);
}
