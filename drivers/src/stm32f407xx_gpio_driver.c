/*
 * stm32f407xx_gpio.c
 *
 *  Created on: Jul 2, 2020
 *      Author: rkosta
 */
#include "stm32f407xx_gpio_driver.h"
/*
 * GPIO Peripheral Clock Control
 * This function Enables or disables peripheral clock for given GPIO port
 *
 * Parameters:
 *  GPIO_RegDef_t *pGPIOx
 *  desired status (0 for disabled, 1 for enabled)
 *
 * Returns:
 *  0 if successful else a true value
 *
 */
/*Static function declarations*/
static uint8_t GPIO_SetMode(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t mode);
static uint8_t GPIO_SetSpeed(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t speed);
static uint8_t GPIO_SetPUPD(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t PUPDmode);
static uint8_t GPIO_SetOutType(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t outtype);
static uint8_t GPIO_SetAltFxnMode(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t altfxnmode);
static uint8_t GPIO_SetInterruptMode(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t mode);
static uint8_t GPIO_SetSysCfg(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t mode);
static uint8_t GPIO_GetGPIONum(GPIO_RegDef_t *pGPIOx);static uint8_t GPIO_IRQDi(const uint8_t IRQnum);
static uint8_t GPIO_IRQEn(const uint8_t IRQnum);
static uint8_t GPIO_IRQDi(const uint8_t IRQnum);

uint8_t GPIO_PClk(GPIO_RegDef_t *pGPIOx,uint8_t status)
{
	if ( status > 1 ){
		return(1);
	}

	if ( pGPIOx == GPIOA )
	{
		if(status)
			GPIOA_PCLK_EN();
		else
			GPIOA_PCLK_DI();
	}
	else if ( pGPIOx == GPIOB )
	{

		if(status)
			GPIOB_PCLK_EN();
		else
			GPIOB_PCLK_DI();
	}
	else if ( pGPIOx == GPIOC )
	{

		if(status)

			GPIOC_PCLK_EN();
		else
			GPIOC_PCLK_DI();
	}
	else if ( pGPIOx == GPIOD )
	{
		if(status)
			GPIOD_PCLK_EN();
		else
			GPIOD_PCLK_DI();
	}
	else if ( pGPIOx == GPIOE )
	{
		if(status)
			GPIOE_PCLK_EN();
		else
			GPIOE_PCLK_DI();
	}
	else if ( pGPIOx == GPIOF )
	{
		if(status)
			GPIOF_PCLK_EN();
		else
			GPIOF_PCLK_DI();
	}
	else if ( pGPIOx == GPIOG )
	{
		if(status)
			GPIOG_PCLK_EN();
		else
			GPIOG_PCLK_DI();
	}
	else if ( pGPIOx == GPIOH )
	{
		if(status)
			GPIOH_PCLK_EN();
		else
			GPIOH_PCLK_DI();
	}
	else if ( pGPIOx == GPIOI )
	{
		if(status)
			GPIOI_PCLK_EN();
		else
			GPIOI_PCLK_DI();
	}




	return(0);
}
uint8_t GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	/*local constant copy of pinconfig structure made for data protection regions*/
	const GPIO_PinConfig_t pinconf = pGPIOHandle->GPIO_PinConfig;

	const uint8_t pinnum = pinconf.GPIO_PinNumber;

	if ( GPIO_SetMode(pGPIOHandle->pGPIOx, pinnum, pinconf.GPIO_PinMode) )
		return(1);
	if ( GPIO_SetSpeed(pGPIOHandle->pGPIOx, pinnum, pinconf.GPIO_PinSpeed) )
		return(1);
	if ( GPIO_SetPUPD(pGPIOHandle->pGPIOx, pinnum, pinconf.GPIO_PinPuPdControl) )
		return(1);
	if ( GPIO_SetOutType(pGPIOHandle->pGPIOx, pinnum, pinconf.GPIO_PinOPType) )
			return(1);
	if ( GPIO_SetAltFxnMode(pGPIOHandle->pGPIOx, pinnum, pinconf.GPIO_PinAltFxnMode) )
			return(1);

	return(0);
}
uint8_t GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	uint8_t gpionum = GPIO_GetGPIONum(pGPIOx);

	RCC->AHB1RSTR |=  (1 << gpionum );				/*write reset bit to register*/
	RCC->AHB1RSTR &= ~(1 << gpionum );				/*clear reset bit from register*/

	return(0);
}
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, const uint8_t pin)
{
	uint8_t value;

	value = (uint8_t )( pGPIOx->IDR >> (pin) ) & 0x01 ;

	return value;
}
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value= (uint16_t )pGPIOx->IDR;

	return(value);
}
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t pin, uint8_t val)
{
	pGPIOx->ODR &= ~(1<<(pin) ); //Clear bitfield space
	pGPIOx->ODR |= (val << (pin) ); //Write to bitfield space

}
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t portval)
{
	pGPIOx->ODR = portval;

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pin)
{
	pGPIOx->ODR ^= (1<<pin);
}
uint8_t GPIO_IRQInterruptConf(const uint8_t IRQnum,const uint8_t status)
{
	if(status)
	{
		return ( GPIO_IRQEn(IRQnum) );
	}
	else
	{
		return( GPIO_IRQDi(IRQnum) );
	}
}
void GPIO_IRQHandle(uint8_t pin)
{
	/*Clear EXTI Pending Register corresponding to pin number*/
	if(EXTI->PR & (1 << pin));		/*if pin's bitpos is not clear*/
	{
		EXTI->PR |= (1 << pin);		/*clear bitpos by writing 1 to it as per register definition*/
	}
}
static uint8_t GPIO_SetMode(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t mode)
{
	/*mode configuration*/

		if(mode>GPIO_MODE_IN_RFT)
			return(1);

		if(mode <= GPIO_MODE_ANALOG)
		{
			/*Regular Mode */
			pGPIOx->MODER &= ~(3<<(2* pin) ); //Clear bitfield space
			pGPIOx->MODER |= (mode << (2 * pin) ); //Write to bitfield space
		}

		else
		{
			GPIO_SetInterruptMode(pGPIOx, pin, mode);
		}

		return(0);
}
static uint8_t GPIO_SetSpeed(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t speed)
{
	/*speed configuration*/
	if(speed>GPIO_SPEED_HIGH)
				return(1);
	pGPIOx->OSPEEDR &= ~(3<<(2* pin) ); //Clear bitfield space
	pGPIOx->OSPEEDR |= (speed << (2 * pin) ); //Write to bitfield space

	return(0);
}
static uint8_t GPIO_SetPUPD(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t PUPDmode)
{
	/*Pull Up/Pull Down mode configuration*/
	if(PUPDmode>GPIO_PIN_PD)
				return(1);
	pGPIOx->PUPDR &= ~(3<<(2* pin) ); //Clear bitfield space
	pGPIOx->PUPDR |= (PUPDmode << (2 * pin) ); //Write to bitfield space

	return(0);
}
static uint8_t GPIO_SetOutType(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t outtype)
{
	if(outtype>GPIO_PIN_PD)
					return(1);

	pGPIOx->OTYPER &= ~(1<<(pin) ); //Clear bitfield space
	pGPIOx->OTYPER |= (outtype << (pin) ); //Write to bitfield space

	return(0);
}
static uint8_t GPIO_SetAltFxnMode(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t altfxnmode)
{
	if( altfxnmode < 8)
	{
		pGPIOx->AFRL &= ~(0xF<<(4* pin) ); //Clear bitfield space
		pGPIOx->AFRL |= (altfxnmode << (4 * pin) ); //Write to bitfield space
	}
	else if( altfxnmode < 15)
	{
			pGPIOx->AFRH &= ~(0xF<<(4* (pin-8) ) ); //Clear bitfield space
			pGPIOx->AFRH |= (altfxnmode << (4 * (pin-8) ) ); //Write to bitfield space
	}
	else
		return(1);

	return(0);
}
static uint8_t GPIO_SetInterruptMode(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t mode)
{
	/*Clear Registers*/
	EXTI->RTST &= ~(1 << pin);		/*Clear rising edge register*/
	EXTI->FTSR &= ~(1 << pin);		/*Clear falling edge register*/

	/*Set corresponding mode registers*/
	switch(mode)
	{
	case  GPIO_MODE_IN_FT:
		EXTI->FTSR |= (1 << pin);	/*enable falling edge by writing to falling edge register*/
		break;
	case  GPIO_MODE_IN_RT:
		EXTI->RTST |= (1 << pin);	/*enable rising edge by writing to rising edge register*/
		break;
	case  GPIO_MODE_IN_RFT:
		EXTI->RTST |= (1 << pin);	/*enable rising edge by writing to rising edge register*/
		EXTI->FTSR |= (1 << pin);	/*enable falling edge by writing to falling edge register*/
		break;
	}
	/*Configure necessary registers in order to enable interrupt mode*/
	EXTI->IMR |= (1 << pin); /*Enable interrupt delivery on pin's exti line via writing to interrupt mask register*/

	GPIO_SetSysCfg(pGPIOx, pin, mode);
	return(0);
}
static uint8_t GPIO_SetSysCfg(GPIO_RegDef_t *pGPIOx, const uint8_t pin, const uint8_t mode)
{
	uint8_t gpionum = GPIO_GetGPIONum(pGPIOx);
	uint8_t regnum = ( pin / 4 );
	uint8_t bitpos = ( (pin % 4) * 4);

	SYSCFG->EXTICR[ (regnum) ] &= ~(0xF << bitpos);					/*clear bit position*/
	SYSCFG->EXTICR[ (regnum) ] |= (gpionum << bitpos);				/*Write to bit position*/

	return(0);
}
static uint8_t GPIO_GetGPIONum(GPIO_RegDef_t *pGPIOx)
{
	uint8_t gpionum;
	if ( pGPIOx == GPIOA )
	{
		gpionum=0;
	}
	else if ( pGPIOx == GPIOB )
	{
		gpionum=1;
	}
	else if ( pGPIOx == GPIOC )
	{
		gpionum=2;
	}
	else if ( pGPIOx == GPIOD )
	{
		gpionum=3;
	}
	else if ( pGPIOx == GPIOE )
	{
		gpionum=4;
	}
	else if ( pGPIOx == GPIOF )
	{
		gpionum=5;
	}
	else if ( pGPIOx == GPIOG )
	{
		gpionum=6;
	}
	else if ( pGPIOx == GPIOH )
	{
		gpionum=7;
	}
	else if ( pGPIOx == GPIOI )
	{
		gpionum=8;
	}

	return(gpionum);
}
static uint8_t GPIO_IRQEn(const uint8_t IRQnum)
{
	if(IRQnum > 90)
		return(1);

	uint8_t regnum = ( IRQnum / 31 );
	uint8_t bitpos = ( IRQnum % 31 );

	NVIC_ISER->REG[regnum] |= ( 1 << bitpos);		/*write 1 to IRQ enable register in corresponding IRQ num pos*/
	return(0);

}
static uint8_t GPIO_IRQDi(const uint8_t IRQnum)
{
	if(IRQnum > 90)									/*max IRQ num on stm32f407x*/
			return(1);

	uint8_t regnum = ( IRQnum / 32 );
	uint8_t bitpos = ( IRQnum % 32 );

	NVIC_ICER->REG[regnum] |= ( 1 << bitpos);		/*write 1 to IRQ Clear register in corresponding IRQ num pos*/
	return(0);
}
uint8_t GPIO_IRQSetPriority(const uint8_t IRQnum, const uint8_t priority)
{
	if(IRQnum > 90)									/*max IRQ num on stm32f407x*/
		return(1);
	if(priority > 0x0F)								/*Priority has a maximum size of 0b1111*/
		return(1);

	uint8_t regnum = ( IRQnum / 4 );
	uint8_t bitpos = ( (IRQnum % 4) * 8 );
	bitpos += ( 8 - NO_IRQ_PR_BITS_IMPLEMENTED );

	NVIC_IPR->REG[regnum] &= ~( 0xF << bitpos);			/*Clear bit positions corresponding to IRQ num in IRQ priority register*/
	NVIC_IPR->REG[regnum] |= ( priority << bitpos);		/*write to bit positions corresponding to IRQ num in IRQ priority register*/

	return(0);
}

