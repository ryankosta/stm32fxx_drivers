/*
 * generic_led_driver.h
 *
 *  Created on: Jul 5, 2020
 *      Author: rkosta
 */

#ifndef INC_GENERIC_LED_DRIVER_H_
#define INC_GENERIC_LED_DRIVER_H_
#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"
/* Defines */
#define LED_GREENLED 0
#define LED_ORANGELED 1
#define LED_REDLED 2
#define LED_BLUELED 3

/*Functions*/
uint8_t ledinit(const uint8_t led); /*Initializes and sets up led*/

uint8_t ledon(const uint8_t led); /*Turns on led*/

uint8_t ledoff(const uint8_t led); /*Turns off led*/

uint8_t ledtoggle(const uint8_t led); /*Toggles led*/

/*Structures*/




#endif /* INC_GENERIC_LED_DRIVER_H_ */
