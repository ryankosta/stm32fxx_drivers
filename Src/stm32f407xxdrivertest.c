/*
 * stm32f407xxdrivertest.c
 *
 *  Created on: Jul 6, 2020
 *      Author: rkosta
 */
#include "stm32f407xxdrivertest.h"
/*internal static fxns*/
static uint8_t ledinittest(void);
static uint8_t ledontest(void);
static void delay(void);
static uint8_t ledofftest(void);

/*
 * Single Led test
 */

uint8_t greenledtest(void){
	if ( ledinit(LED_GREENLED) )
			return(1);
	if ( ledon(LED_GREENLED) )
		return(1);
	return(0);
}
uint8_t orangeledtest(void){
	if ( ledinit(LED_ORANGELED) )
			return(1);
	if ( ledon(LED_ORANGELED) )
		return(1);
	return(0);
}
uint8_t redledtest(void){
	if ( ledinit(LED_REDLED) )
			return(1);
	if ( ledon(LED_REDLED) )
		return(1);
	return(0);
}
uint8_t blueledtest(void){
	if ( ledinit(LED_BLUELED) )
			return(1);
	if ( ledon(LED_BLUELED) )
		return(1);
	return(0);
}
/*
 * All led tests
 */

uint8_t ledtestseq(void)
{
	if ( greenledtest() )
		return(1);
	delay();
	if ( orangeledtest() )
			return(1);
	delay();
	if ( redledtest() )
			return(1);
	delay();
	if ( blueledtest() )
			return(1);
	delay();
	return(0);
}
uint8_t ledtestparallel(void)
{
	if( ledinittest() )
		return(1);
	if( ledontest() )
		return(1);

	return(0);
}
uint8_t ledblinktest(uint8_t ttblink)
{
	if( ledinittest() )
		return(1);
	for(uint8_t i = 0 ; i < ttblink; i ++)
	{
		if( ledontest() )
			return(1);
		delay();
		if( ledofftest() )
			return(1);
		delay();
	}
	return(0);
}
uint8_t ledbuttontest(uint8_t ttwait)
{
	buttoninit(BTN_BLUEBUTTON);
	for(int i = 0; i<ttwait ; ++i)
	{
		if (buttonread(BTN_BLUEBUTTON))
			ledblinktest(1);
		delay();
		delay();
	}




	return(0);
}
/*
 * Static local functions
 */

static uint8_t ledinittest(void)
{
	if ( ledinit(LED_GREENLED) )
		return(1);
	if ( ledinit(LED_ORANGELED) )
		return(1);
	if ( ledinit(LED_REDLED) )
		return(1);
	if ( ledinit(LED_BLUELED) )
		return(1);
	return(0);
}
static uint8_t ledontest(void)
{
	if ( ledon(LED_GREENLED) )
		return(1);
	if ( ledon(LED_ORANGELED) )
		return(1);
	if ( ledon(LED_REDLED) )
		return(1);
	if ( ledon(LED_BLUELED) )
		return(1);
	return(0);
}
static uint8_t ledofftest(void)
{
	if ( ledoff(LED_GREENLED) )
		return(1);
	if ( ledoff(LED_ORANGELED) )
		return(1);
	if ( ledoff(LED_REDLED) )
		return(1);
	if ( ledoff(LED_BLUELED) )
		return(1);
	return(0);
}
static void delay(void)
{
	for(uint32_t i = 0 ; i < 500000 ; i ++);
}




