/**
 * @file GPIO.hpp
 * @author your name Fady Nashaat
 * @brief This file have the prototypes of generic GPIO Driver
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


extern void PIC_Initialize_GPIO(void);
extern void PIC_PinMode(unsigned char pin_num,unsigned char pin_mode);
extern void PIC_Write_Pin(unsigned char pin_num,unsigned char signal);
extern unsigned char PIC_Read_Pin(unsigned char pin_num);

extern void AVR_Initialize_GPIO(void);
extern void AVR_PinMode(unsigned char pin_num,unsigned char pin_mode);
extern void AVR_Write_Pin(unsigned char pin_num,unsigned char signal);
extern unsigned char AVR_Read_Pin(unsigned char pin_num);

typedef enum {
    PIC=0,
    AVR
}MC_Type;

class GPIO
{
    private:
        MC_Type MC;     //type of the microcontroller
    public:
        GPIO(MC_Type mc);   //default constructor
        void PinMode(unsigned char pin_num,unsigned char pin_mode);
        void Write_Pin(unsigned char pin_num,unsigned char signal);
        unsigned char Read_Pin(unsigned char pin_num);
};

