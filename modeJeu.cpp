// 
// 
// 

#include "modeJeu.h"
#include "LiquidCrystal.h"
#include <Keypad.h>

extern int pinBT1, pinBT2, pinBT3, pinBT4, pinBT5, pinCLE1, pinCLE2, pinCLE3; // ici les pins ou sont branchés les boutons
extern LiquidCrystal LCD;
extern Keypad keypad;
extern const char NO_KEY;

#define OPE 0
#define ARMEE 1
#define DESARMER 2
#define BOOM 3

int bombEtat = 0; //0 = Opérationel, 1 = Armé, 2 = Désarmé, 3 = Boom 
char key = keypad.getKey(); // affiche le keypad


bool cle() // mode Cle uniquement

{


	int fin = 0;
	int T_cle[3];
	T_cle[0] = pinCLE1;
	T_cle[1] = pinCLE2;
	T_cle[2] = pinCLE3;

	return false;
}

void code(int codeDesamorcage)// mode Code uniquement
{
	int touche = 0;
	int placementEcran = 0;
	int i = 0;
	int t = 0;

	switch (bombEtat) 
	{
		LCD.clear();

		case OPE:
		{
			int Code;

			LCD.clear();
			LCD.setCursor(0, 0);
			delay(100);
			LCD.print("Entrer le code :"); //Demander le Code a l'utilisateur.
			while (i < 3)
			{
				int J = 0;
				while (J < 2)
				{


					if (key != NO_KEY)//si une touche est préssée
					{
						LCD.setCursor(placementEcran, 1);
						LCD.print(key);
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
						LCD.print("Code Valide");
						delay(500);
						LCD.clear();
						bombEtat = ARMEE; //debut du compte a rebours
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
					{
						break;
					}
					}
				}

				touche = 0;
				i++;
			}

			break;
		}
		


		case ARMEE:
		{
			char Key = keypad.getKey();
			if (Key == '#')	
			{
				char reslutaCode;
				LCD.clear();
				LCD.setCursor(0, 0);
				delay(100);
				LCD.print("Entre Le Code :"); //si la touche de désarmement # est pressée, l'utilisateur peux entrer le code.
				while (i < 3)
				{
					int J = 0;
					while (J < 2)
					{


						if (key != NO_KEY)//si une touche est préssée
						{
							LCD.setCursor(placementEcran, 1);
							LCD.print(key);
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
							LCD.print("Code Valide");
							delay(500);
							LCD.clear();
							bombEtat = ARMEE; //debut du compte a rebours
						}
						case '*': //Efface la saisi
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

					touche = 0;
					i++;
				}


				if (reslutaCode == true) 
				{
					LCD.clear();
					bombEtat = DESARMER; //la bombe passe a l'etat désarmer.

				}
			}

		}
	}
}


void fils() // mode fils uniquement
{
	
}


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

//-------------------------------------- fin des fonctions primaires



