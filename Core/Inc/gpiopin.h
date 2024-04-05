#ifndef GPIOPIN_H_
#define GPIOPIN_H_

#include "stm32f1xx_hal.h"

class GPIO
{
private:
    GPIO_TypeDef* 	mGPIOPort;
    uint16_t 		mGPIOPin;


public:
    GPIO(GPIO_TypeDef* port, uint16_t pin );   // Constructor

    bool readPin();			//< @brief This function reads the pin.
    void setPin();
    void clearPin();
    void togglePin();
};

#endif /* GPIOPIN_H_ */