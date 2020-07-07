/*
 * generic_button_driver.h
 *
 *  Created on: Jul 6, 2020
 *      Author: rkosta
 */

#ifndef INC_GENERIC_BUTTON_DRIVER_H_
#define INC_GENERIC_BUTTON_DRIVER_H_

/*
 *Includes
 */
#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

/*
 * Function declarations
 */
uint8_t buttonread(uint8_t button);
uint8_t buttoninit(const uint8_t button);
uint8_t buttoninterruptinit(const uint8_t button);

/*
 * Macros
 */
/*Button types for buttoninit fxn*/

/*Button options (of type uint_8) */
#define BTN_BLUEBUTTON 0


#endif /* INC_GENERIC_BUTTON_DRIVER_H_ */
