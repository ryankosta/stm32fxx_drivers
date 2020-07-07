/*
 * generic_button_driver_test.h
 *
 *  Created on: Jul 7, 2020
 *      Author: rkosta
 */
/*
 * NOTE: DEFINES INTERRUPT FUNCTION EXTI0, DONT INCLUDE IN BUILD UNLESS TO TEST DRIVER OR BOARD FUNCTIONALITY
 */


#ifndef GENERIC_BUTTON_DRIVER_TEST_H_
#define GENERIC_BUTTON_DRIVER_TEST_H_
/*
 * Library includes
 */
#include <stdint.h>

/*
 * Header includes
 */
#include "stm32f407xx.h"
#include "generic_button_driver.h"
#include "generic_led_driver.h"

/*
 * Functions
 */
uint8_t buttoninterrupttest(const uint8_t button);


#endif /* GENERIC_BUTTON_DRIVER_TEST_H_ */
