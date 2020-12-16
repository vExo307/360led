//Thanks to www.free60.org/SMC for helping me get front LEDs right

//Credit to TeamFSD for this wonderful SMC stuff

#pragma once
#ifndef _SMC__H
#define _SMC_H

#include <string.h>

#define POWER_LED_BLINK            0x10
#define POWER_LED_DEFAULT        0x02
#define POWER_LED_ON            0x01
#define POWER_LED_OFF            0X03

typedef enum _LEDState
{
    OFF        = 0x00,
    RED        = 0x08,
    GREEN    = 0x80,
    ORANGE    = 0x88
}LEDState;

extern "C" void __stdcall HalSendSMCMessage(void* input, void* output);

class smc
{
    public:
        void SetLEDS(LEDState sTopLeft, LEDState sTopRight, LEDState sBottomLeft, LEDState sBottomRight);
    private:
		//This is used to store our SMC data
		unsigned char m_SMCMessage[16];
		unsigned char m_SMCReturn[16];
		void PrepareBuffers();
};

#endif
