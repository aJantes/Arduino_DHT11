#include "cjt_DHT11.h"

cjt_DHT11::cjt_DHT11(int pin)
{
    data_pin = pin;
}
void cjt_DHT11::cjt_DHT11_Init()
{
    pinMode(data_pin, OUTPUT);

    digitalWrite(data_pin, LOW); //主机发送开始信号
    delay(30);

    digitalWrite(data_pin, HIGH); ///主机把总线拉高等待响应
    delayMicroseconds(40);
    pinMode(data_pin, INPUT_PULLUP);
    while (digitalRead(data_pin) != LOW)
        ;

    delayMicroseconds(80);
    if (digitalRead(data_pin) == LOW)
        ;

    delayMicroseconds(80);
}
unsigned char cjt_DHT11::cjt_DHT11_Read_Bit()
{
    unsigned char data = 0, i;

    pinMode(data_pin, INPUT_PULLUP);
    delayMicroseconds(2);
    for (i = 0; i < 8; i++)
    {

        while (digitalRead(data_pin) != HIGH)
            ;
        delayMicroseconds(40);
        if (digitalRead(data_pin) == HIGH)
        {
            data |= (1 << (7 - i));
        }
        while (digitalRead(data_pin) != LOW)
            ;
    }
    return data;
}

void cjt_DHT11::cjt_DHT11_Read()
{
    cjt_DHT11_Init();

    dht11_humt = cjt_DHT11_Read_Bit();
    cjt_DHT11_Read_Bit();
    dht11_temp = cjt_DHT11_Read_Bit();
    cjt_DHT11_Read_Bit();
    cjt_DHT11_Read_Bit();

    delayMicroseconds(50);

    pinMode(data_pin, OUTPUT);
    digitalWrite(data_pin, HIGH); //总线拉高进入空闲状态
}