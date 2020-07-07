/*
 * stm32f407xxdrivertest.h
 *
 *  Created on: Jul 6, 2020
 *      Author: rkosta
 */

#ifndef STM32F407XXDRIVERTEST_H_
#define STM32F407XXDRIVERTEST_H_

#include "stm32f407xx.h"
#include <stdint.h>
#include "stm32f407xx_gpio_driver.h"
#include "generic_led_driver.h"
#include "generic_button_driver.h"

/*
 * Tests
 */
uint8_t ledtestseq(void); /*test leds by running all individual led tests*/
uint8_t ledtestparallel(void); /*test leds by initializing all of them, then enabling all of them*/
uint8_t ledblinktest(uint8_t ttblink); /*Led Blink test, ttblink is times to blink */
uint8_t ledbuttontest(uint8_t ttwait); /*runs ledblinktest(1) when button is pressed, times to wait is number of cycles to wait for button press*/



uint8_t greenledtest(void);
uint8_t orangeledtest(void);
uint8_t redledtest(void);
uint8_t blueledtest(void);


#endif /* STM32F407XXDRIVERTEST_H_ */
