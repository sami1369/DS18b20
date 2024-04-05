#include "eventLoop.h"
#include "main.h"
#include "gpiopin.h"
#include "led.h"
// Main Cpp to run application
void projectMainCPP()
{
  	GPIO  	*gpio1;
    LED 	*led1;
    gpio1 = new GPIO(LD2_GPIO_Port, LD2_Pin );  
	led1  = new LED(gpio1);
	while(1)
	{
		for(int i = 0; i < 10000000; i++);		// arbitrary delay
		led1->toggle();
	}

}



// Define all C function calls from main.c below
extern "C"
{
    void projectMain()
    {
        projectMainCPP();
    }
}