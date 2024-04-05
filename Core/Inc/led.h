#ifndef LED_H_
#define LED_H_

#include "gpiopin.h"
#include "main.h"

class LED
{
public:
    GPIO *gpio;
    int32_t luminance;

    LED(GPIO *gpio_);

    //LED(GPIO gpio_);

    void On();
    void Off();
	void toggle();
};

#endif /* LED_H_ */