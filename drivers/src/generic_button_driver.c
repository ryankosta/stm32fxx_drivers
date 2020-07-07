/*
 * generic_button_driver.c
 *
 *  Created on: Jul 6, 2020
 *      Author: rkosta
 */
#include "generic_button_driver.h"
typedef struct{
	GPIO_RegDef_t *pGPIOx; 		/*Pointer that holds base address of GPIO port to which pin belongs*/
	uint8_t pinnum; /* This holds GPIO pin number*/
}Button_handle_t;

static Button_handle_t buttoninfo(const uint8_t button);



uint8_t buttoninit(const uint8_t button)
{
	Button_handle_t buttonhandle;
	buttonhandle = ( buttoninfo(button) );

	GPIO_PinConfig_t buttonpinconf = {
		buttonhandle.pinnum,
		GPIO_MODE_IN,
		GPIO_OUT_TYPE_PP,
		GPIO_SPEED_LOW,
		GPIO_NO_PUPD,
		0
	};

	GPIO_Handle_t buttonpinhandle = {
			buttonhandle.pGPIOx,
			buttonpinconf
	};
	GPIO_PClk(buttonpinhandle.pGPIOx, 1);
	GPIO_Init(&buttonpinhandle);
	return(0);

}
uint8_t buttoninterruptinit(const uint8_t button)
{
	Button_handle_t buttonhandle;
	buttonhandle = ( buttoninfo(button) );

	GPIO_PinConfig_t buttonpinconf = {
		buttonhandle.pinnum,
		GPIO_MODE_IN_FT,
		GPIO_OUT_TYPE_PP,
		GPIO_SPEED_LOW,
		GPIO_NO_PUPD,
		0
	};

	GPIO_PClk(buttonpinhandle.pGPIOx, 1);
	GPIO_Init(&buttonpinhandle);

	if (buttonhandle.pinnum <= 4)
		GPIO_IRQInterruptConf( (buttonhandle.pinnum + 5), 1);
	else if (buttonhandle.pinnum <= 9)
		GPIO_IRQInterruptConf(23, 1);
	else
		GPIO_IRQInterruptConf(40, 1);

	return(0);

}

uint8_t buttonread(uint8_t button)
{
	uint8_t val;
	Button_handle_t buttonhandle;

	buttonhandle = ( buttoninfo(button) );

	val = GPIO_ReadPin(buttonhandle.pGPIOx, buttonhandle.pinnum);

	return(val);
}



static Button_handle_t buttoninfo(const uint8_t button){

	Button_handle_t buttonhandle;
	switch(button)
	{
	case BTN_BLUEBUTTON :
		buttonhandle.pinnum = 0;
		buttonhandle.pGPIOx= GPIOA;
		break;
	}

	return(buttonhandle);
}


