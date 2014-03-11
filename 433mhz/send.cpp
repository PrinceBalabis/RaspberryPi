/*
Usage: ./send <unitCode>
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {    
	int PIN = 0;
	int unitCode = atoi(argv[1]);

	if (wiringPiSetup() == -1) return 1;
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);

	mySwitch.send(unitCode, 24);

	return 0;
}
