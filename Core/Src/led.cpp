#include "led.h"


LED::LED(GPIO *gpio_)
{
    gpio = gpio_;
}

void LED::on()
{
    // luminance = 100;
    gpio->setPin();
}

void LED::off()
{
    // luminance = 0;
    gpio->clearPin();
}

void LED::toggle()
{
	gpio->togglePin();
}