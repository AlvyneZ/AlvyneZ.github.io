/**
 *****************************************************************************************************************************************
 * @file			: stm32f446xx.h
 * @author			: AlvyneZ
 * @brief			: Register Addresses and Register definitions for the stm32f446xx
 *****************************************************************************************************************************************
 */
#ifndef INC_STM32F446XX_H_		//Include Guard (INC_STM32F446XX_H_)
#define INC_STM32F446XX_H_


#include <stdint.h>		/*	For the uint notation for integers	*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//				Implementation of printf like feature using ARM Cortex M3/M4/ ITM functionality
//				This function will not work for ARM Cortex M0/M0+
//				The STM32 F4 family comes with a Cortex M4 processor
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/*	Debug Exception and Monitor Control Register base address	*/
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/*	ITM register addresses	*/
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )
/*	Function For enabling the ITM (Instrumentation Trace Macrocell) peripheral	*/
void ITM_EnableTrace(uint8_t port);
/*	Function For sending debugging text to ITM (Instrumentation Trace Macrocell) FIFO	*/
void ITM_SendChar(uint8_t ch);

#endif		//Include Guard (INC_STM32F446XX_H_)