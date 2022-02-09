/**
 * @file GPIO.cpp
 * @author your name Fady Nashaat
 * @brief This file contains brief implementation of the class GPIO
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"AVR_GPIO.h"
#include"PIC_GPIO.h"
#include"GPIO.hpp"

GPIO::GPIO(MC_Type mc)
{
    MC=mc;
    switch (MC)
    {
    case PIC:
        PIC_Initialize_GPIO();
        break;
    
    case AVR:
        AVR_Initialize_GPIO();
        break;
    }
}

void GPIO::PinMode(unsigned char pin_num,unsigned char pin_mode)
{
    switch (MC)
    {
    case PIC:
        PIC_PinMode(pin_num,pin_mode);
        break;
    
    case AVR:
        AVR_PinMode(pin_num,pin_mode);
        break;
    }
}

void GPIO::Write_Pin(unsigned char pin_num,unsigned char signal)
{
    switch (MC)
    {
    case PIC:
        PIC_Write_Pin(pin_num,signal);
        break;
    
    case AVR:
        AVR_Write_Pin(pin_num,signal);
        break;
    }
}

unsigned char GPIO::Read_Pin(unsigned char pin_num)
{
    unsigned char res;
    switch (MC)
    {
    case PIC:
        res=PIC_Read_Pin(pin_num);
        break;
    
    case AVR:
        res=AVR_Read_Pin(pin_num);
        break;
    }
    return res;
}
