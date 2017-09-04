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


bool setupModeJeu()  //corriger la fonction !!
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
				LCD.setCursor(0, 1);
				LCD.print("Cles Desactive  ");
				modeCle = false;
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 1);
				LCD.print("Cles Active     ");
				modeCle = true;
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT2) > 0)
		{
			if (modeCode == true)
			{
				LCD.setCursor(0, 1);
				LCD.print("Code Desactive  ");
				modeCode = false;
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 1);
				LCD.print("Code Active     ");
				modeCode = true;
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT3) > 0)
		{
			if (modeFils == true)
			{
				LCD.setCursor(0, 1);
				LCD.print("Fils Desactive  ");
				modeFils = false;
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 1);
				LCD.print("Fils Active     ");
				modeFils = true;
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT5) > 0) //valider
		{

			fin = 1;
			delay(2000);

			//setupcode();
		}

		if (digitalRead(pinBT1) && digitalRead(pinBT2)) // mode test
		{
			modeTest();
		}
	}



	return modeCle, modeCode, modeFils;
}


unsigned int setupTempsDePartie()
{
	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Temps de partie?");
	LCD.setCursor(1, 0); // ligne du bas 1 ere case

	char tempsDePartie[8] = { 0,0,':',1,5,':',0,0 }; //position 3 et 6 a ne pas toucher
	char positionChiffreARemplir = 0;
	char tour = 0;

	unsigned int tempsDePartieEnSecondes = 0;


	while (tour == 8) //on passe 6 fois, 1 pour chaque chiffre + 2 pour les ":"
	{

		char chiffreEntre = keypad.getKey(); //recupere la touche presse

		if (chiffreEntre != NO_KEY) //si la recuperation n'es pas vide
		{
			if (tour != 3 || 6)
			{
				tempsDePartie[tour] = chiffreEntre;

				LCD.setCursor(tour, 1);
				LCD.print(chiffreEntre);

				tour++;
			}
			else
			{
				tour++;
				LCD.setCursor(tour, 1);
				LCD.print(tempsDePartie[tour]);
			}


		}



	}

	return tempsDePartieEnSecondes;
}

