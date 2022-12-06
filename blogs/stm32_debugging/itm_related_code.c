/**
 *****************************************************************************************************************************************
 * @file			: stm32f446xx.c
 * @author			: AlvyneZ
 * @brief			: Functions specific to the Cortex M4 with FPU
 *****************************************************************************************************************************************
 */
#include "itm_related_code.h"


/**
 *****************************************************************************************************************************************
 * @fn           	- ITM_EnableTrace
 * @brief			- Enables the ITM trace peripheral of the Cortex processor
 * @param[port]		- Stimulus port to be enabled
 * @return			- None
 */
void ITM_EnableTrace(uint8_t port){

	//Enable TRCENA
	DEMCR |= ( 1 << 24);			// DEMCR = *((volatile uint32_t*) 0xE000EDFCUL )

	//enable the required stimulus port
	ITM_TRACE_EN |= ( 1 << port);	// ITM_TRACE_EN = *((volatile uint32_t*) 0xE0000E00UL )
}


/**
 *****************************************************************************************************************************************
 * @fn           	- ITM_SendChar
 * @brief			- Loads a byte into the ITM FIFO buffer (stimulus port 0) for debugging purposes
 * @param[ch]		- Byte to be loaded into FIFO buffer
 * @return			- None
 */
void ITM_SendChar(uint8_t ch){

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 0x1UL));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = ch;		// ITM_STIMULUS_PORT0 = *((volatile uint32_t*) 0xE0000000UL )
}


/**
 *****************************************************************************************************************************************
 * @fn           	- _write
 * @brief			- Overrides low-level weak system call that prints characters
 */
int _write(int file, char *ptr, int len) {
    int DataIdx;
    for (DataIdx = 0; DataIdx < len; DataIdx++) {
        ITM_SendChar(*ptr++);
    }
    return len;
}