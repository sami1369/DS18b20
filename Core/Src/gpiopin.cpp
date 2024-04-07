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

void GPIO::setPinInput(GPIO_TypeDef *port, uint16_t pin){
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void GPIO::setPinOutput(GPIO_TypeDef *port, uint16_t pin){
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}