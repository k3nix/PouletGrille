// developpeur.h

#ifndef _DEVELOPPEUR_h
#define _DEVELOPPEUR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void modeTest();
void demoLancement();

#endif

