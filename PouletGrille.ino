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
byte rowPins[4] = { 7, 6, 5, 4 }; //connect to the row pinouts of the keypad
byte colPins[3] = { 3 , 2 , 1 }; //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 3);





void setup() //fonction lancée une seule fois au demmarage de l'arduino
{

	LCD.begin(16, 2); //on declare 16 colonnes et 2 lignes
	LCD.print("Gyromitres Bomb");
<<<<<<< HEAD
	LCD.setCursor(0, 1); // on passe a la deuxiemme ligne
	LCD.print("Version 0.4");
	delay(500);
=======
	LCD.setCursor(0, 1); // on passe a la deuciemme ligne
	LCD.print("Version 0.3");
	delay(2000);
>>>>>>> 73d04f57fac2b5d91e25feba03da3e69848f7a1a

	LCD.clear();

	pinMode(pinBT1, INPUT);
	pinMode(pinBT2, INPUT);
	pinMode(pinBT3, INPUT);
	pinMode(pinBT4, INPUT);
	pinMode(pinBT5, INPUT);
	pinMode(pinCLE1, INPUT);
	pinMode(pinCLE2, INPUT);
	pinMode(pinCLE3, INPUT);
	
	pinMode(44, OUTPUT); //pin du relais --> Lumiere G

	//pinMode(A0, OUTPUT);
	//pinMode(A1, OUTPUT);
	//pinMode(A2, OUTPUT);
}

void loop()
{
	
	setupTempsDePartie();
	
	

}




