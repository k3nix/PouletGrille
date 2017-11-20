

#include "menus.h"
#include "LiquidCrystal.h"
#include <Keypad.h>
#include "developpeur.h"


extern int pinBT1, pinBT2, pinBT3, pinBT4, pinBT5, pinCLE1, pinCLE2, pinCLE3;
extern LiquidCrystal LCD;
extern Keypad keypad;
extern const char NO_KEY;
extern int ledCle, ledCode, ledFils;


bool setupModeJeu()  //corriger la fonction !!
{
	int fin = 1;
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

	while (fin != 0)
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

		if (digitalRead(pinBT1) != 0)
		{
			if (modeCle == true)
			{
				LCD.setCursor(0, 1);
				LCD.print("Cles Desactive  ");
				modeCle = false;
				digitalWrite(ledCle, LOW);
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 1);
				LCD.print("Cles Active     ");
				modeCle = true;
				digitalWrite(ledCle, HIGH);
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT2) != 0)
		{
			if (modeCode == true)
			{
				LCD.setCursor(0, 1);
				LCD.print("Code Desactive  ");
				modeCode = false;
				digitalWrite(ledCode, LOW);
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 1);
				LCD.print("Code Active     ");
				modeCode = true;
				digitalWrite(ledCode, HIGH);
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
		}

		if (digitalRead(pinBT3) != 0)
		{
			if (modeFils == true)
			{
				LCD.setCursor(0, 1);
				LCD.print("Fils Desactive  ");
				modeFils = false;
				digitalWrite(ledFils, LOW);
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
			else
			{
				LCD.setCursor(0, 1);
				LCD.print("Fils Active     ");
				modeFils = true;
				digitalWrite(ledFils, HIGH);
				delay(2000);
				LCD.setCursor(0, 1);
				LCD.print("                ");
			}
		}


		if (digitalRead(pinBT1) && digitalRead(pinBT2)) // mode test
		{
			modeTest();
		}
	}



	return modeCle, modeCode, modeFils;
}
/*
unsigned long setupTempsDePartie()
{
	int touche = 0;
	int placementEcran = 0;
	int i = 0;
	int t = 0;

	char tempsDePartie[8] = { 0,0,':',1,5,':',0,0 }; //position 3 et 6 a ne pas toucher

	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Temps de partie?");
	LCD.setCursor(1, 0);

	while (i < 3) // 3 groupes de 2 chiffres hh:mm:ss
	{
		int J = 0;
		while (J < 2) // recuperation des deux chiffres
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

		if (placementEcran == 2 || placementEcran == 5) // placer les deux points
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




	delay(500000);
	unsigned long converti = 0;

	//converti = convertTempsPartieSecondes();
	return converti;
}
*/

unsigned long setupTempsDePartie()
{
	LCD.clear();
	LCD.setCursor(0, 0);
	LCD.print("Temps de partie?");
	LCD.setCursor(1, 0); // ligne du bas 1 ere case

	char tempsDePartie[8] = { 0,0,':',1,5,':',0,0 }; //position 3 et 6 a ne pas toucher
	int tour = 0;

	unsigned int tempsSeconde = 1;

	LCD.setCursor(0, 1);
	LCD.print("..:..:..");

	while (tour != 8) //on passe 6 fois, 1 pour chaque chiffre + 2 pour les ":"
	{

		char saisie = keypad.getKey(); //recupere la touche presse

		if (tour == 2 | tour == 5) //sur les deux points
		{
			tour += 1;
			LCD.setCursor(tour, 1);

		}

		if (saisie != NO_KEY)//si une touche est préssée
		{
			switch (saisie)
			{
			case '#': //touche valider
			{
				if (tour != 8)
				{
					LCD.setCursor(0, 0);
					LCD.print("! ! ! ! ! ! ! ! ");
					delay(1000);
					LCD.setCursor(0, 0);
					LCD.print("Completez temps!");
					delay(2000);
					LCD.setCursor(0, 0);
					LCD.print("Temps de partie?");
					LCD.setCursor(tour, 1);
					break;
				}
				else
				{
					LCD.clear();
					LCD.setCursor(0, 0);
					LCD.print("Temps Valide");
				}



			}
			case '*': // touche corriger
			{
				LCD.setCursor(0, 0);
				LCD.print("CORR");
				delay(500);

				LCD.setCursor(0, 0);
				LCD.print("Temps de partie?");

				switch (tour)
				{
				case -1: //curseur au debut impossible de suppr
				{
					break;
				}
				case 3:
				{
					tour -= 1;
					tour -= 1;
					LCD.setCursor(tour, 1);
					LCD.print('.');
					LCD.setCursor(tour, 1);
					tour -= 1;
					break;
				}
				case 6:
				{
					tour -= 1;
					tour -= 1;
					LCD.setCursor(tour, 1);
					LCD.print('.');
					LCD.setCursor(tour, 1);
					tour -= 1;
					break;
				}

				default:
					tour -= 1;
					LCD.setCursor(tour, 1);
					LCD.print('.');
					LCD.setCursor(tour, 1);
					tour -= 1;

					break;
				}
				break;
			}
			default:
				tempsDePartie[tour] = saisie;

				LCD.setCursor(tour, 1);
				LCD.print(saisie);
				tour++;
				break;
			}


		}


	}
	delay(2000);


	//tempsSeconde = convertTempsPartieSecondes(tempsDePartie[0], tempsDePartie[1], tempsDePartie[3], tempsDePartie[4], tempsDePartie[6], tempsDePartie[7]);

	LCD.clear();

	//delay(10000);

	return tempsSeconde;
}


unsigned long convertTempsPartieSecondes(char heures1, char heures2, char minutes1, char minutes2, char secondes1, char secondes2)
{
	unsigned long tempsConverti = 0;

	unsigned int heures = heures1 + heures2;
	unsigned int minutes = minutes1 + minutes2;
	unsigned int secondes = secondes1 + secondes2;


	tempsConverti = heures;




	return tempsConverti;
}



