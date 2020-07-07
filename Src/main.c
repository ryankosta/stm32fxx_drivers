/*
 * main.c
 *
 *  Created on: Jul 2, 2020
 *      Author: rkosta
 */
#include "stm32f407xx.h"
#include "stm32f407xxdrivertest.h"
int main(void)
{

	ledbuttontest(25);
	for(;;);
}
