/*
 * stm32f407xx.h
 *
 *  Created on: Jul 2, 2020
 *      Author: rkosta
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>
/*******************START: ARM CORTEX M4 SPECIFIC DETAILS******************************/
/*
 * Base addresses
 */
/*NVIC Registers*/
#define NVIC_ISER_BASEADDR					0xE000E100		/*Base address of NVIC Interrupt Set Enable Registers*/
#define NVIC_ICER_BASEADDR					0xE000E180		/*Base address of NVIC Interrupt Clear Enable Registers*/
#define NVIC_ISPR_BASEADDR					0xE000E200		/*Base address of NVIC Interrupt Set Pending Registers*/
#define NVIC_ICPR_BASEADDR					0xE000E280		/*Base address of NVIC Interrupt Clear Pending Registers*/
#define NVIC_IABR_BASEADDR					0xE000E300		/*Base address of NVIC Interrupt Active Bit Registers*/
#define NVIC_IPR_BASEADDR					0xE000E400		/*Base address of NVIC Priority Registers*/
/*
 * Structures
 */
typedef struct
{
	volatile uint32_t REG[8];								/*NVIC  Interrupt set enable registers 0-7 			| Offset 0x00*/
}NVIC_ISER_RegDef_t;

typedef struct{
	volatile uint32_t REG[8];								/*NVIC  Interrupt Clear enable registers 0-7 		| Offset 0x00*/
}NVIC_ICER_RegDef_t;

typedef struct{
	volatile uint32_t REG[8];								/*NVIC  Interrupt Set Pending registers 0-7 		| Offset 0x00*/
}NVIC_ISPR_RegDef_t;

typedef struct{
	volatile uint32_t REG[8];								/*NVIC  Interrupt Clear Pending registers 0-7 		| Offset 0x00*/
}NVIC_ICPR_RegDef_t;

typedef struct{
	volatile uint32_t REG[8];								/*NVIC  Interrupt Active Bit registers 0-7 			| Offset 0x00*/
}NVIC_IABR_RegDef_t;

typedef struct{
	volatile uint32_t REG[60];								/*NVIC  Interrupt Priority registers 0-59	 		| Offset 0x00*/
}NVIC_IPR_RegDef_t;

/*
 * definitions (base addresses typecasted to xxx_RegDef_t
 */

/* NVIC definitions */
#define NVIC_ISER	( (NVIC_ISER_RegDef_t*) NVIC_ISER_BASEADDR)
#define NVIC_ICER	( (NVIC_ICER_RegDef_t*) NVIC_ICER_BASEADDR)
#define NVIC_ISPR	( (NVIC_ISPR_RegDef_t*) NVIC_ISPR_BASEADDR)
#define NVIC_ICPR	( (NVIC_ICPR_RegDef_t*) NVIC_ICPR_BASEADDR)
#define NVIC_IABR	( (NVIC_ISER_RegDef_t*) NVIC_IABR_BASEADDR)
#define NVIC_IPR	( (NVIC_IPR_RegDef_t* )	NVIC_IPR_BASEADDR)


/*******************END: ARM CORTEX M4 SPECIFIC DETAILS******************************/


/*** Base Addresses *IRQPRIORITYBITSIMPLEMENTED**/

/* Base addresses of Flash and SRAM memory
 *
 */
#define FLASH_BASEADDR 				0x08000000U		 /*Base address of flash*/
#define SRAM1_BASEADDR				0x20000000U		 /*Base address of SRAM 1*/
#define SRAM2_BASEADDR				0x2001C000U		 /*Base address of SRAM 2*/
#define SRAM 						SRAM1_BASEADDR	 /*Base address of SRAM*/
#define ROM							0x1FFF0000U		 /*Base address of ROM*/

/* Base addresses of bus domains
 *
 */
#define PERIPH_BASEADDR				0x40000000U		 /*Base address of peripheral busses*/
#define APB1PERIPH_BASEADDR			PERIPH_BASE		 /*Base address of APB1 peripheral bus*/
#define APB2PERIPH_BASEADDR			0x40010000U		 /*Base address of APB2 peripheral bus*/
#define AHB1PERIPH_BASEADDR			0x40020000U		 /*Base address of AHB1 peripheral bus*/
#define AHB2PERIPH_BASEADDR			0x50000000U		 /*Base address of AHB2 peripheral bus*/


/* Base addresses of peripherals on APB1 bus
 *
 */

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800U)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00U)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400U)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0x4800U)

#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0x4C00U)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0x5000U)

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400U)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800U)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00U)

/*Base addresses of peripherals on APB2 bus
 *
 */
#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000U)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400U)

#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000U)

#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800U)

#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00U)

/*
 *  Base addresses of peripherals on AHB1 bus
 */

/*GPIO base addresses*/
#define GPIOA_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x2000U)
#define GPIOJ_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x2400U)
#define GPIOK_BASEADDR 				(AHB1PERIPH_BASEADDR + 0x2800U)

/*RCC base address*/
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800U)

/*** Peripheral register definition structures***/

/*
 * Note: Peripheral registers specific to MCU
 */

/* GPIO structure */
typedef struct
{
	volatile uint32_t MODER;				/*Configures I/O direction mode 			| Offset 0x00*/
	volatile uint32_t OTYPER;				/*Switches Between push-pull and open-drain | Offset 0x04*/
	volatile uint32_t OSPEEDR;				/*Controls I/O output speed 				| Offset 0x08*/
	volatile uint32_t PUPDR;				/*Configures pull up and pull down resistors|Offset 0x0C*/
	volatile uint32_t IDR;					/*Holds input data. READ ONLY				|Offset 0x10*/
	volatile uint32_t ODR;					/*Sends output data.						|Offset 0x14*/
	volatile uint32_t BSRR;					/*TODO: ADD DESCRIPTION						|Offset 0x18*/
	volatile uint32_t LCKR;					/*Locks configuration of port bits          |Offset 0x1C*/
	volatile uint32_t AFRL;					/*Alternate function Low register  (p1-p7)	|Offset 0x20*/
	volatile uint32_t AFRH;					/*Alternate function high register (p8-p15)	|Offset 0x24*/
}GPIO_RegDef_t;

/*RCC structure*/
typedef struct{
	volatile uint32_t CR;					/*| Offset 0x00*/
	volatile uint32_t PLLCFGR;				/*| Offset 0x04*/
	volatile uint32_t CFGR;					/*| Offset 0x08*/
	volatile uint32_t CIR;					/*| Offset 0x0C*/

	volatile uint32_t AHB1RSTR;				/*| Offset 0x10*/
	volatile uint32_t AHB2RSTR;				/*| Offset 0x14*/
	volatile uint32_t AHB3RSTR;				/*| Offset 0x18*/
	volatile uint32_t RESERVED_1;			/*Reserved Block 							| Offset 0x1C*/
	volatile uint32_t APB1RSTR;				/*| Offset 0x20*/
	volatile uint32_t APB2RSTR;				/*| Offset 0x24*/

	volatile uint32_t RESERVED_2;			/*Reserved Block 							| Offset 0x28*/
	volatile uint32_t RESERVED_3;			/*Reserved Block 							| Offset 0x2C*/

	volatile uint32_t AHB1ENR;				/*| Offset 0x30*/
	volatile uint32_t AHB2ENR;				/*| Offset 0x34*/
	volatile uint32_t AHB3ENR;				/*| Offset 0x38*/
	volatile uint32_t RESERVED_4;			/*Reserved Block 							| Offset 0x3C*/
	volatile uint32_t APB1ENR;				/*| Offset 0x40*/
	volatile uint32_t APB2ENR;				/*| Offset 0x44*/

	volatile uint32_t RESERVED_5;			/*Reserved Block 							| Offset 0x48*/
	volatile uint32_t RESERVED_6;			/*Reserved Block 							| Offset 0x4C*/

	volatile uint32_t AHB1LPENR;			/*| Offset 0x50*/
	volatile uint32_t AHB2LPENR;			/*| Offset 0x54*/
	volatile uint32_t AHB3LPENR;			/*| Offset 0x58*/
	volatile uint32_t RESERVED_7;			/*Reserved Block 							| Offset 0x5C*/
	volatile uint32_t APB1LPENR;			/*| Offset 0x60*/
	volatile uint32_t APB2LPENR;			/*| Offset 0x64*/

	volatile uint32_t RESERVED_8;			/*Reserved Block 							| Offset 0x68*/
	volatile uint32_t RESERVED_9;			/*Reserved Block 							| Offset 0x6C*/

	volatile uint32_t BDCR;					/*| Offset 0x70*/
	volatile uint32_t CSR;					/*| Offset 0x74*/

	volatile uint32_t RESERVED_10;			/*Reserved Block 							| Offset 0x78*/
	volatile uint32_t RESERVED_11;			/*Reserved Block 							| Offset 0x7C*/

	volatile uint32_t SSCGR;				/*| Offset 0x80*/
	volatile uint32_t PLLI2SCFGR;			/*| Offset 0x84*/
	volatile uint32_t PLLSAICFGR;			/*| Offset 0x88*/
	volatile uint32_t PLLDCKCFGR;			/*| Offset 0x8C*/

}RCC_RegDef_t;

/*EXTI register structure*/
typedef struct
{
	volatile uint32_t IMR;					/*TODO: add short desc						| Offset 0x00*/
	volatile uint32_t EMR;					/*TODO: add short desc						| Offset 0x04*/
	volatile uint32_t RTST;					/*TODO: add short desc						| Offset 0x08*/
	volatile uint32_t FTSR;					/*TODO: add short desc						| Offset 0x0C*/
	volatile uint32_t SWIER;				/*TODO: add short desc						| Offset 0x10*/
	volatile uint32_t PR;					/*TODO: add short desc						| Offset 0x14*/

}EXTI_RegDef_t;

/*SYSCFG register structure*/
typedef struct
{
	volatile uint32_t MEMRMP;				/*TODO: add short desc 						| Offset 0x00*/
	volatile uint32_t PMC;					/*TODO: add short desc 						| Offset 0x04*/
	volatile uint32_t EXTICR[4];			/*TODO: add short desc 						| Offset 0x08-0x14*/
	volatile uint32_t RESERVED1[2];			/*Reserved			 						| Offset 0x1C*/
	volatile uint32_t CMPCR;				/*TODO: add short desc 						| Offset 0x20*/
	volatile uint32_t RESERVED2[2];			/*Reserved									| Offset 0x24-28*/
	volatile uint32_t CFGR;					/*TODO: add short desc 						| Offset 0x2C*/

}SYSCFG_RegDef_t;
/*
 * Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t
 */

/* GPIOX Definitions */
#define GPIOA		( (GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB		( (GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC		( (GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD		( (GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE		( (GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF		( (GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG		( (GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH		( (GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI		( (GPIO_RegDef_t*) GPIOI_BASEADDR)
#define GPIOJ		( (GPIO_RegDef_t*) GPIOJ_BASEADDR)
#define GPIOK		( (GPIO_RegDef_t*) GPIOK_BASEADDR)

/* EXTI definition*/
#define EXTI 		( (EXTI_RegDef_t*) EXTI_BASEADDR)

/* RCC Definition */
#define RCC			( (RCC_RegDef_t*) RCC_BASEADDR)
/* SYSCFG definition */
#define SYSCFG ( (SYSCFG_RegDef_t*) SYSCFG_BASEADDR)
/*
 * Peripheral clock enable definitions
 */

/* GPIO Peripheral clock enable definitions */
#define GPIOA_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 0 )  )
#define GPIOB_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 1 )  )
#define GPIOC_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 2 )  )
#define GPIOD_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 3 )  )
#define GPIOE_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 4 )  )
#define GPIOF_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 5 )  )
#define GPIOG_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 6 )  )
#define GPIOH_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 7 )  )
#define GPIOI_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 8 )  )
#define GPIOJ_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 9 )  )
#define GPIOK_PCLK_EN()  ( RCC->AHB1ENR |= (1 << 10)  )

/*SPi Peripheral clock enable definitions */
#define SPI1_PCLK_EN()   ( RCC->APB1ENR |= (1 << 12)  )

#define SPI2_PCLK_EN()   ( RCC->APB1ENR |= (1 << 14)  )
#define SPI3_PCLK_EN()   ( RCC->APB1ENR |= (1 << 15)  )

/* USARTx Peripheral clock enable definitions */
#define USART1_PCLK_EN() ( RCC->APB2ENR |= (1 << 4 )  )

#define USART2_PCLK_EN() ( RCC->APB1ENR |= (1 << 17)  )
#define USART3_PCLK_EN() ( RCC->APB1ENR |= (1 << 18)  )
#define USART4_PCLK_EN() ( RCC->APB1ENR |= (1 << 19)  )
#define USART5_PCLK_EN() ( RCC->APB1ENR |= (1 << 20)  )

#define USART6_PCLK_EN() ( RCC->APB2ENR |= (1 << 5 )  )


/* I2Cx Peripheral clock enable definitions */
#define I2C1_PCLK_EN()   ( RCC->APB1ENR |= (1 << 21)  )
#define I2C2_PCLK_EN()   ( RCC->APB1ENR |= (1 << 22)  )
#define I2C3_PCLK_EN()   ( RCC->APB1ENR |= (1 << 23)  )



/* UART Peripheral clock enable definitions */
#define UART7_PCLK_EN() ( RCC->APB1ENR |= (1 << 30)  )
#define UART8_PCLK_EN() ( RCC->APB1ENR |= (1 << 31)  )


/* SYSCFG Peripheral clock enable definition */
#define SYSCFG_PCLK_EN() ( RCC->APB2ENR |= (1 << 14) )

/*
 * Peripheral clock disable definitions
 */



/* GPIO Peripheral clock disable definitions */
#define GPIOA_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 0 )  )
#define GPIOB_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 1 )  )
#define GPIOC_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 2 )  )
#define GPIOD_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 3 )  )
#define GPIOE_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 4 )  )
#define GPIOF_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 5 )  )
#define GPIOG_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 6 )  )
#define GPIOH_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 7 )  )
#define GPIOI_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 8 )  )
#define GPIOJ_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 9 )  )
#define GPIOK_PCLK_DI()  ( RCC->AHB1ENR &= ~(1 << 10)  )

/*SPi Peripheral clock disable definitions */
#define SPI1_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 12)  )

#define SPI2_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 14)  )
#define SPI3_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 15)  )

/* USARTx Peripheral clock disable definitions */
#define USART1_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 4 )  )

#define USART2_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 17)  )
#define USART3_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 18)  )
#define USART4_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 19)  )
#define USART5_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 20)  )

#define USART6_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 5 )  )


/* I2Cx Peripheral clock disable definitions */
#define I2C1_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 21)  )
#define I2C2_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 22)  )
#define I2C3_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 23)  )



/* UART Peripheral clock enable definitions */
#define UART7_PCLK_EN() ( RCC->APB1ENR |= (1 << 30)  )
#define UART8_PCLK_EN() ( RCC->APB1ENR |= (1 << 31)  )

/* SYSCFG Peripheral clock enable definition */
#define SYSCFG_PCLK_EN() ( RCC->APB2ENR |= (1 << 14) )
/*
 * IRQ Numbers of STM32F407x MCU
 * Also Known As: Vector Table
 */
/*EXTI IRQ numbers*/
#define IRQ_NO_EXTI0			6		/*EXTI line 0 Interrupts			|Address 0x0000 0058*/
#define IRQ_NO_EXTI1			7		/*EXTI line 1 Interrupts			|Address 0x0000 005C*/
#define IRQ_NO_EXTI2			8		/*EXTI line 2 Interrupts			|Address 0x0000 0060*/
#define IRQ_NO_EXTI3			9		/*EXTI line 3 Interrupts			|Address 0x0000 0064*/
#define IRQ_NO_EXTI4			10		/*EXTI line 4 Interrupts			|Address 0x0000 0068*/

#define IRQ_NO_EXTI9_5			23		/*EXTI lines 5-9 Interrupts			|Address 0x0000 009C*/
#define IRQ_NO_EXTI15_10		40		/*EXTI lines 10-15 Interrupts		|Address 0x0000 00E0*/

/*CAN1 IRQ numbers*/
#define IRQ_NO_CAN1_TX			19		/*CAN1 TX interrupts 				|Address 0x0000 008C*/
#define IRQ_NO_CAN1_RX0			20		/*CAN1 RX0 interrupts 				|Address 0x0000 0090*/
#define IRQ_NO_CAN1_RX1			21		/*CAN1 RX1 interrupts 				|Address 0x0000 0094*/
#define IRQ_NO_CAN1_SCE			22		/*CAN1 SCE interrupts 				|Address 0x0000 009C*/

/*I2C IRQ numbers*/
#define I2C1_EV					31		/*I2C1 event interrupt				|Address 0x0000 00BC*/
#define I2C1_ER					32		/*I2C1 error interrupt				|Address 0x0000 00C0*/
#define I2C2_EV					33		/*I2C2 event interrupt				|Address 0x0000 00C4*/
#define I2C2_ER					34		/*I2C1 error interrupt				|Address 0x0000 00C8*/

/*SPI IRQ numbers*/
#define SPI1					35		/*SPI1 global interrupt				|Address 0x0000 00CC*/
#define SPI2					36		/*SPI2 global interrupt				|Address 0x0000 00D0*/

/*USART IRQ numbers*/
#define USART1					37		/*USART1 global interrupt			|Address 0x0000 00D4*/
#define USART2					38		/*USART2 global interrupt			|Address 0x0000 00D8*/
#define USART3					39		/*USART3 global interrupt			|Address 0x0000 00DC*/

/*
 * General Macros
 */
#define NO_IRQ_PR_BITS_IMPLEMENTED 4
#endif /* INC_STM32F407XX_H_ */
