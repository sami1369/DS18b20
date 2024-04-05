#include "led.h"


LED::LED(GPIO *gpio_)
{
    gpio = gpio_;
}

void LED::On()
{
    // luminance = 100;
    gpio->setPin();
}

void LED::Off()
{
    // luminance = 0;
    gpio->clearPin();
}

void LED::toggle()
{
	gpio->togglePin();
}