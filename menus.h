// menus.h

#ifndef _MENUS_h
#define _MENUS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

bool setupModeJeu();
unsigned long setupTempsDePartie();
unsigned long convertTempsPartieSecondes(char heures1, char heures2, char minutes1, char minutes2, char secondes1, char secondes2);

#endif

