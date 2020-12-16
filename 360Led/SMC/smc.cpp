#include "smc.h"
#include <cstdio>


//Credit to TeamFSD for this wonderful SMC stuff

void smc::PrepareBuffers()
{
	memset( m_SMCMessage, 0, sizeof(m_SMCMessage));
	memset( m_SMCReturn, 0,  sizeof(m_SMCReturn) );
}

void smc::SetLEDS(LEDState sTopLeft, LEDState sTopRight, LEDState sBottomLeft, LEDState sBottomRight)
{
	PrepareBuffers();
    m_SMCMessage[0] = 0x99;
    m_SMCMessage[1] = 0x01;

	m_SMCMessage[2] = ((unsigned char)(sTopLeft>>3) | (unsigned char)(sTopRight>>2) | (unsigned char)(sBottomLeft>>1) | (unsigned char)(sBottomRight));

	HalSendSMCMessage(m_SMCMessage, NULL);
}