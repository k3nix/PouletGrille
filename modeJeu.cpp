// 
// 
// 

#include "modeJeu.h"
#include "LiquidCrystal.h"
#include "Keypad.h"

extern int pinBT1, pinBT2, pinBT3, pinBT4, pinBT5, pinCLE1, pinCLE2, pinCLE3; // ici les pins ou sont branchés les boutons
extern LiquidCrystal LCD;
extern Keypad keypad;
extern const char NO_KEY;

void cle() // mode clé uniquement
{

	while (true) //
	{

	}
	
		
		/*if (digitalRead(pinCLE1) > 0)
	{
		LCD.clear();
		LCD.setCursor(0, 1);
		LCD.print("   Mode Cle1    ");
		delay(500);
	}

	if (digitalRead(pinCLE2) > 0)
	{
		LCD.clear();
		LCD.setCursor(0, 1);
		LCD.print("   Mode Cle2    ");
		delay(500);
	}

	if (digitalRead(pinCLE3) > 0)
	{
		LCD.clear();
		LCD.setCursor(0, 1);
		LCD.print("   Mode Cle3    ");
		delay(500);
	}*/

}

void code() // mode code uniquement
{

}

void fils() // mode fils uniquement
{

}

//-------------------------------------- fin des fonctions primaires

void cleCode() //mode code + mode clé
{

}

void cleFils() // mode cle + fils
{

}

void codeFils() // mode code + fils
{

}

void cleCodeFils() // mode clé + code + fils
{

}

void modeDrapeaux() // mode drapeaux 
{

}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
// Fin des fonctions principales inserer les fonctions annexes en dessous
