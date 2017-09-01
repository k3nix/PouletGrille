// 
// 
// 

#include "menus.h"
#include "LiquidCrystal.h"
#include "Keypad.h"
#include "developpeur.h"

extern int pinBT1, pinBT2, pinBT3, pinBT4, pinBT5, pinCLE1, pinCLE2, pinCLE3;
extern LiquidCrystal LCD;
extern Keypad keypad;
extern const char NO_KEY;

char tempsDePartie[6] = { 0,0,1,5,0,0 }; //Par defaut 15 minutes

bool choixJeu()
{
	int fin = 0;
	int T_boutons[3];
	T_boutons[0] = pinBT1;
	T_boutons[1] = pinBT2;
	T_boutons[2] = pinBT3;

	bool modeCle = false;
	bool modeCode = false;
	bool modeFils = false;

	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Mode de jeu ?");
	delay(200);

	while (fin == 0)
	{
		char key = keypad.getKey();

		if (key != NO_KEY)//si une touche est préssée
		{
			switch (key)
			{
			case '#':
			{
				LCD.clear();
				LCD.setCursor(0, 0);
				LCD.print("Choix Valides");
				delay(1000);
				LCD.clear();
				exit;
				break;
			}
			default:
				break;
			}

		}

		if (digitalRead(pinBT1) > 0)
		{
			if (modeCle == true)
			{
				LCD.setCursor(0, 2);
				LCD.print("Cles Desactive  ");
				modeCle = false;
				delay(2000);
				LCD.setCursor(0, 2);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 2);
				LCD.print("Cles Active     ");
				modeCle = true;
				delay(2000);
				LCD.setCursor(0, 2);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT2) > 0)
		{
			if (modeCode == true)
			{
				LCD.setCursor(0, 2);
				LCD.print("Code Desactive  ");
				modeCle = false;
				delay(2000);
				LCD.setCursor(0, 2);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 2);
				LCD.print("Code Active     ");
				modeCode = true;
				delay(2000);
				LCD.setCursor(0, 2);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT3) > 0)
		{
			if (modeFils == true)
			{
				LCD.setCursor(0, 2);
				LCD.print("Fils Desactive  ");
				modeFils = false;
				delay(2000);
				LCD.setCursor(0, 2);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 2);
				LCD.print("Fils Active     ");
				modeFils = true;
				delay(2000);
				LCD.setCursor(0, 2);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT5) > 0) //valider
		{

			fin = 1;
			delay(2000);
		}

		if (digitalRead(pinBT1) && digitalRead(pinBT2)) // mode test
		{
			modeTest();
		}
	}



	return modeCle, modeCode, modeFils;
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

