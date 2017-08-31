// 
// 
// 

#include "developpeur.h"

void clignioteG()
{
	do
	{
		digitalWrite(44, HIGH);
		delay(1000);
		digitalWrite(44, LOW);
		delay(1000);
	} while (true);
	
}
