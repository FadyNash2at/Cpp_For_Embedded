/**
 * @file PIC_GPIO.h
 * @author your name Fady_Nashat
 * @brief This file contain the prototypes function for PIC will communicate with the MicroController
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

void PIC_Initialize_GPIO(void);
void PIC_PinMode(unsigned char pin_num,unsigned char pin_mode);
void PIC_Write_Pin(unsigned char pin_num,unsigned char signal);
unsigned char PIC_Read_Pin(unsigned char pin_num);
