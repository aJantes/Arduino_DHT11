
#ifndef __CJT_DHT11__
#define __CJT_DHT11__

#include <Arduino.h>

class cjt_DHT11
{
private:
    int data_pin;

public:
    cjt_DHT11(int pin);
    void cjt_DHT11_Init();
    unsigned char cjt_DHT11_Read_Bit();
    void cjt_DHT11_Read();
    unsigned char dht11_temp, dht11_humt;
};

#endif