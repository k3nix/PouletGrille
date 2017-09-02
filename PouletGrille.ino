#include "developpeur.h"
#include "sons.h"
#include "controlLeds.h"
#include "menus.h"
#include "modeJeu.h"
#include "Keypad.h"
#include "Arduino.h"
#include <LiquidCrystal.h>


//bibliotheque interne
//#include <string.h
using namespace std;

// ---------------------------------------------------------Espace variables
int pinBT1 = 52, pinBT2 = 51, pinBT3 = 50, pinBT4 = 49, pinBT5 = 48, pinCLE1 = 47, pinCLE2 = 46, pinCLE3 = 45; // ici les pins ou sont branchés les boutons

LiquidCrystal LCD(13, 12, 11, 10, 9, 8); // creation de l'objet LCD portée globale


char keys[4][3] = {
	{ '1','2','3' },
	{ '4','5','6' },
	{ '7','8','9' },
	{ '*','0','#' }
};
byte rowPins[4] = { 7, 6, 5, 4 }; //connectez-vous à la ligne pinouts du clavier
byte colPins[3] = { 3 , 2 , 1 }; //connectez-vous à la colonne des brochures du clavier
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 3);

char tempsDePartie[6] = { 0,0,1,5,0,0 }; //Par defaut 15 minutes



void setup()
{

	LCD.begin(16, 2); //on declare 16 colonnes et 2 lignes
	LCD.print("Gyromitres Bomb");
	LCD.setCursor(0, 1); // on passe a la deuciemme ligne
	LCD.print("Version 0.3");
	delay(500);

	LCD.clear();

	pinMode(pinBT1, INPUT);
	pinMode(pinBT2, INPUT);
	pinMode(pinBT3, INPUT);
	pinMode(pinBT4, INPUT);
	pinMode(pinBT5, INPUT);
	pinMode(pinCLE1, INPUT);
	pinMode(pinCLE2, INPUT);
	pinMode(pinCLE3, INPUT);
	
	pinMode(44, OUTPUT); //relais

	//pinMode(A0, OUTPUT);
	//pinMode(A1, OUTPUT);
	//pinMode(A2, OUTPUT);
}

void loop()
{
	
	setupTempsDePartie();
	
	//clignioteG();

	//modeTest(); //mode de test des boutons

	//choixJeu();
	
	

}

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
