/*
 * generic_button_driver_test.c
 *
 *  Created on: Jul 7, 2020
 *      Author: rkosta
 */
#include "generic_button_driver_test.h"

uint8_t buttoninterrupttest(const uint8_t button)
{
	ledinit(LED_BLUELED);
	buttoninterruptinit(button);
	return(0);
}
void EXTI0_IRQHandler(void)
{
	ledtoggle(LED_BLUELED);
	GPIO_IRQHandle(0);
}
