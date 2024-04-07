#include "eventLoop.h"
#include "gpiopin.h"
#include "led.h"
#include "main.h"
#include "onewire.h"
#include "stm32f1xx_hal.h"
#include <cstdint>

// Main Cpp to run application
void projectMainCPP() {
  GPIO      *gpio1, *gpio2;
  LED       *led1;
  OneWire   *oneWire1;

  uint8_t   tempByte1, tempByte2;
  int       Presence;
  uint16_t  temp;
  float     temperature = 0;

  gpio1 =     new GPIO(LD2_GPIO_Port, LD2_Pin);
  gpio2 =     new GPIO(DS18b20_GPIO_Port, DS18b20_Pin);
  led1  =     new LED(gpio1);
  oneWire1 =  new OneWire(gpio2);

  while (1) {
    // delay(50000); // Microsecond delay

    Presence = oneWire1->startOneWire();
    HAL_Delay(1);
    oneWire1->writeOneWire(0xCC);               //Skip ROM
    oneWire1->writeOneWire(0x44);               //convert temperature
    HAL_Delay(800);

    Presence = oneWire1->startOneWire();
    HAL_Delay(1);
    oneWire1->writeOneWire(0xCC);               //Skip ROM
    oneWire1->writeOneWire(0xBE);               //convert temperature

    tempByte1 = oneWire1->readOneWire();
    tempByte2 = oneWire1->readOneWire();

    temp = (tempByte2 << 8) | tempByte1;
    temperature = (float)temp / 16;

    HAL_Delay(1000);
    led1->toggle();
  }
}

// Define all C function calls from main.c below
extern "C" {
void projectMain() { projectMainCPP(); }
}
