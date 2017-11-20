// 
// 
// 

#include "developpeur.h"
#include "LiquidCrystal.h"
#include <Keypad.h>

extern int pinBT1, pinBT2, pinBT3, pinBT4, pinBT5, pinCLE1, pinCLE2, pinCLE3;
extern LiquidCrystal LCD;
extern Keypad keypad;
extern const char NO_KEY;

void modeTest()
{
	if (digitalRead(pinBT1) > 0)
	{
		if (digitalRead(pinBT2) > 0)
		{
			LCD.clear();
			LCD.setCursor(0, 0);
			LCD.print("Mode TEST");
			delay(2000);
			bool finTest = false;

			while (finTest == false)
			{
				LCD.clear();

				if (digitalRead(pinBT1) > 0)
				{
					if (digitalRead(pinBT2) > 0)
					{
						LCD.clear();
						LCD.setCursor(0, 0);
						LCD.print("Fin du Test");
						delay(2000);
						finTest = true;
					}
					LCD.clear();
					LCD.print("Mode Cles");
					delay(50);

				}

				if (digitalRead(pinBT2) > 0)
				{
					LCD.clear();
					LCD.print("Mode Code");
					delay(50);
				}

				if (digitalRead(pinBT3) > 0)
				{
					LCD.clear();
					LCD.print("Mode Fils");
					delay(50);
				}

				if (digitalRead(pinBT4) > 0)
				{
					LCD.clear();
					LCD.print("Equipe Bleue");
					delay(50);
				}

				if (digitalRead(pinBT5) > 0)
				{
					LCD.clear();
					LCD.print("Equipe Orange");
					delay(50);
				}

				if (digitalRead(pinCLE1) > 0)
				{
					LCD.clear();
					LCD.print("Cle 1");
					delay(50);
				}

				if (digitalRead(pinCLE2) > 0)
				{
					LCD.clear();
					LCD.print("Cle 2");
					delay(50);
				}

				if (digitalRead(pinCLE3) > 0)
				{
					LCD.clear();
					LCD.print("Cle 3");
					delay(50);
				}

				char key = keypad.getKey(); // affiche le keypad

				if (key != NO_KEY)//si une touche est préssée
				{
					LCD.print(key);
					delay(500);
				}

			}
		}
	}
}

void demoLancement()
{
	int temps = 50;
	int C = 0;

	while (C != 5)
	{

		digitalWrite(44, LOW);

		digitalWrite(A0, HIGH);
		delay(temps);
		digitalWrite(A1, HIGH);
		delay(temps);
		digitalWrite(A2, HIGH);
		delay(temps);
		digitalWrite(A0, LOW);
		delay(temps);
		digitalWrite(A1, LOW);
		delay(temps);
		digitalWrite(A2, LOW);
		delay(temps);
		digitalWrite(44, HIGH);
		delay(temps);
		C = C + 1;
	}
	
}
