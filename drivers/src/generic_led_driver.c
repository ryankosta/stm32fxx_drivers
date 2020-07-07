/*
 * generic_led_driver.c
 *
 *  Created on: Jul 5, 2020
 *      Author: rkosta
 */
#include "generic_led_driver.h"
/*structs*/

typedef struct{
	GPIO_RegDef_t *pGPIOx; 		/*Pointer that holds base address of GPIO port to which pin belongs*/
	uint8_t pinnum; /* This holds GPIO pin number*/
}LED_handle_t;

static LED_handle_t ledinfo(const uint8_t led);

uint8_t ledinit(const uint8_t led)
{
	LED_handle_t ledhandle = ( ledinfo(led) );

	GPIO_PinConfig_t ledpinconf = {
		ledhandle.pinnum,
		GPIO_MODE_OUT,
		GPIO_OUT_TYPE_PP,
		GPIO_SPEED_LOW,
		GPIO_NO_PUPD,
		0
	};

	GPIO_Handle_t ledpinhandle = {
			ledhandle.pGPIOx,
			ledpinconf
	};
	GPIO_PClk(ledpinhandle.pGPIOx, 1);
	GPIO_Init(&ledpinhandle);
	return(0);

}

uint8_t ledon(uint8_t led)
{
	LED_handle_t ledhandle = ( ledinfo(led) );
	GPIO_WritePin(ledhandle.pGPIOx, ledhandle.pinnum, 1);

	return(0);
}

uint8_t ledoff(uint8_t led)
{
	LED_handle_t ledhandle = ( ledinfo(led) );
	GPIO_WritePin(ledhandle.pGPIOx, ledhandle.pinnum, 0);

	return(0);
}

/*led selector, implemented in its own function to allow easier addition of leds*/
static LED_handle_t ledinfo(const uint8_t led){

	LED_handle_t ledhandle;
	switch(led)
	{
	case LED_GREENLED :
		ledhandle.pinnum = 12;
		ledhandle.pGPIOx=GPIOD;
		break;
	case LED_ORANGELED :
		ledhandle.pinnum = 13;
		ledhandle.pGPIOx=GPIOD;
		break;
	case LED_REDLED :
		ledhandle.pinnum = 14;
		ledhandle.pGPIOx=GPIOD;
		break;
	case LED_BLUELED :
		ledhandle.pinnum = 15;
		ledhandle.pGPIOx=GPIOD;
		break;
	}

	return(ledhandle);
}

