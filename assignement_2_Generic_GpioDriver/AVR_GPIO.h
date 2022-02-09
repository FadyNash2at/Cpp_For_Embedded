/**
 * @file AVR_GPIO.h
 * @author your name Fady Nashaat
 * @brief This file contain the prototypes function for AVR will communicate with the MicroController
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

void AVR_Initialize_GPIO(void);
void AVR_PinMode(unsigned char pin_num,unsigned char pin_mode);
void AVR_Write_Pin(unsigned char pin_num,unsigned char signal);
unsigned char AVR_Read_Pin(unsigned char pin_num);
