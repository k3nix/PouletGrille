// menus.h

#ifndef _MENUS_h
#define _MENUS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

bool setupModeJeu();
char setupTempsDePartie();

#endif

