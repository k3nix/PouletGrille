// 
// 
// 

#include "menus.h"
extern LiquidCrystal LCD;
extern Keypad keypad;
extern const char NO_KEY;

void choixModeJeu()
{
	
}

void setupTempsDePartie()
{
	int touche = 0;
	int placementEcran = 0;
	int i = 0;
	int t = 0;
	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Temps de partie?");
	LCD.setCursor(1, 0);

	while (i < 3)
	{
		int J = 0;
		while (J < 2)
		{
			char key = keypad.getKey(); // affiche le keypad

			if (key != NO_KEY)//si une touche est préssée
			{
				LCD.setCursor(placementEcran, 1);
				LCD.print(key);
				tempsDePartie[t] = key;
				placementEcran += 1;
				touche = touche + 1;
				t++;
				J++;
			}
			switch (key)
			{
			case '#':
			{
				LCD.clear();
				LCD.setCursor(0, 0);
				LCD.print("Temps Valide");

			}
			case '*':
			{
				if (placementEcran < 1)
				{
					touche = touche - 1;
					placementEcran = placementEcran - 1;
					LCD.setCursor(placementEcran, 1);
					LCD.print(" ");
				}

			}
			default:
				break;
			}
		}

		if (placementEcran == 2 || placementEcran == 5)
		{
			LCD.setCursor(placementEcran, 1);
			placementEcran += 1;

			touche = touche - 1;
			LCD.print(":");
		}



		touche = 0;
		i++;
	}




	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Valider ?");

	int compteur = 1;

	while (compteur = 6)
	{
		LCD.setCursor(compteur, 1);
		LCD.print(tempsDePartie[compteur]);
		compteur++;
	}


	delay(500000);
}

