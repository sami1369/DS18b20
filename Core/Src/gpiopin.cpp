#include "gpiopin.h"

GPIO::GPIO(GPIO_TypeDef *port, uint16_t pin)
    : mGPIOPort(port), mGPIOPin(pin)
{
    
}


bool GPIO::readPin()
{
    return HAL_GPIO_ReadPin(mGPIOPort, mGPIOPin);
}

void GPIO::setPin()
{
    HAL_GPIO_WritePin(mGPIOPort, mGPIOPin, GPIO_PIN_SET);
}

void GPIO::clearPin()
{
    HAL_GPIO_WritePin(mGPIOPort, mGPIOPin, GPIO_PIN_RESET);
}

void GPIO::togglePin()
{
    HAL_GPIO_TogglePin(mGPIOPort, mGPIOPin);
}
