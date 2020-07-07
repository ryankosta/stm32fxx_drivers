/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Jul 2, 2020
 *      Author: rkosta
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*** Typedef structs ***/

/*Config structure for gpio pin */
typedef struct{
	uint8_t GPIO_PinNumber;			/*Possible values from 0 to 15*/
	uint8_t GPIO_PinMode;			/*Possible values from @GPIO_PIN_MODES*/
	uint8_t GPIO_PinOPType;			/*Possible values from @GPIO_PIN_OUT_TYPES*/
	uint8_t GPIO_PinSpeed;			/*Possible values from @GPIO_PIN_OUT_SPEEDS*/
	uint8_t GPIO_PinPuPdControl;	/*Possible values from @GPIO_PIN_PUPD*/
	uint8_t GPIO_PinAltFxnMode;		/*Possible values from 0 to 15*/
}GPIO_PinConfig_t;


/*Handle structure for gpio pin */
typedef struct{
	GPIO_RegDef_t *pGPIOx; 		/*Pointer that holds base address of GPIO port to which pin belongs*/
	GPIO_PinConfig_t GPIO_PinConfig; /* This holds GPIO pin configuration settings*/
}GPIO_Handle_t;

/*** Defines ***/
/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN			0				/*Input Mode*/
#define GPIO_MODE_OUT			1				/*Output Mode*/
#define GPIO_MODE_ALTFN			2				/*Alternate Function mode*/
#define GPIO_MODE_ANALOG		3				/*Analog input mode*/

#define GPIO_MODE_IN_FT			4				/*Falling edge interrupt mode*/
#define GPIO_MODE_IN_RT			5				/*Rising edge interrupt mode*/
#define GPIO_MODE_IN_RFT		6				/*Rising Falling edge interrupt mode*/
/*
 * @GPIO_PIN_OUT_TYPES
 * GPIO pin possible output types
 */
#define GPIO_OUT_TYPE_PP		0				/*Push-Pull output mode*/
#define GPIO_OUT_TYPE_OD		1				/*Open Drain output mode*/

/*
 * @GPIO_PIN_OUT_SPEEDS
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW 			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3
/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull up pull down configuration macros
 */
#define GPIO_NO_PUPD			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2






/*** Function Prototypes ***/

uint8_t GPIO_PClk(GPIO_RegDef_t *pGPIOx,uint8_t status);			     				/*Enable GPIO port Peripheral clock*/

uint8_t GPIO_Init(GPIO_Handle_t *pGPIOhandle);						    				/*Initialize GPIO pin*/
uint8_t GPIO_DeInit(GPIO_RegDef_t *p);								     				/*Reset all registers of GPIO port/ deinitialize GPIO port*/

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t pin);		         				/*Read from GPIO Pin*/
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);					         				/*Read from GPIO port*/

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t pin, uint8_t val);	 				/*Write to GPIO Pin*/
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t portval);   						/*Write to GPIO Port*/

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pin);			 				/*Toggle GPIO pin output mode*/

uint8_t GPIO_IRQInterruptConf(const uint8_t IRQnum, const uint8_t status);				/*Enable or Disable interrupts for GPIO IRQ number */
uint8_t GPIO_IRQSetPriority(const uint8_t IRQnum, const uint8_t priority);				/*configure Interrupt priority*/
void GPIO_IRQHandle(uint8_t pin);														/*Process interupt when it occurs*/







#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
