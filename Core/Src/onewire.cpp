#include "onewire.h"
#include "main.h"
#include <cstdint>

OneWire::OneWire(GPIO *gpio_) 
{ 
    gpio = gpio_; 
}

uint8_t OneWire::startOneWire(void)
{


  int Response = 0;
  gpio->setPinOutput(DS18b20_GPIO_Port, DS18b20_Pin);       // set the pin as output
  gpio->clearPin ();                                        // pull the pin low
  delay(480);                                               // delay according to datasheet

  gpio->setPinInput(DS18b20_GPIO_Port, DS18b20_Pin);        // set the pin as input
  delay(80);                                                // delay according to datasheet

  if (!(gpio->readPin()))
    Response = 1;                                           // if the pin is low i.e the presence pulse is detected
  else
    Response = -1;

  delay(400);                                               // 480 us delay totally.

  return Response;
}


void OneWire::writeOneWire(uint8_t data)
{
    gpio->setPinOutput(DS18b20_GPIO_Port, DS18b20_Pin);             // set the pin as output
    for (int i = 0; i < 8; i++) {
       if ((data & (1 << i)) != 0)                                  // if the bit is high
       {
        //write 1 on bus
        gpio->setPinOutput(DS18b20_GPIO_Port, DS18b20_Pin);         // set the pin as output
        gpio->clearPin();                                           // pull the pin low
        delay(1);

        gpio->setPinInput(DS18b20_GPIO_Port, DS18b20_Pin);          // set the pin as input
        delay(50);                                                  // delay according to datasheet
       }
       else
       {
        // write 0 on bus
        gpio->setPinOutput(DS18b20_GPIO_Port, DS18b20_Pin);         // set the pin as output
        gpio->clearPin();                                           // pull the pin low
        delay(50);

        gpio->setPinInput(DS18b20_GPIO_Port, DS18b20_Pin);          // set the pin as input
        // delay(10);
       }
    }
}

uint8_t OneWire::readOneWire(void)
{
    uint8_t value=0;
    gpio->setPinInput(DS18b20_GPIO_Port, DS18b20_Pin);               // set the pin as input

    for (int i = 0; i < 8; i++) 
    {
      gpio->setPinOutput(DS18b20_GPIO_Port, DS18b20_Pin);           // set the pin as output
      gpio->clearPin();                                             // pull the pin low
      delay(1);

      gpio->setPinInput(DS18b20_GPIO_Port, DS18b20_Pin);            // set the pin as input

      if ((gpio->readPin()))                                        // if the pin is HIGH
      {
        value |= 1<<i;
      }
      delay (50);  // wait for 60 us
    }
    return value;
}
