#include <cstdlib>
#include <iostream>
#include "../libraries/RF24/RF24.h"
#include "../libraries/RF24NetworkPi/RF24Network.h"
#include <ctime>
#include <stdio.h>
#include <time.h>

/**
 * Usage:
 * ./sendRF24Command {nodeOfReceiver} {commandToSend}
 * example ./sendRF24Command 00 01
 **/
using namespace std;

// CE Pin, CSN Pin, SPI Speed

// Setup for GPIO 22 CE and GPIO 25 CSN with SPI Speed @ 1Mhz
//RF24 radio(RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_18, BCM2835_SPI_SPEED_1MHZ);

// Setup for GPIO 22 CE and CE0 CSN with SPI Speed @ 4Mhz
//RF24 radio(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_4MHZ); 

// Setup for GPIO 22 CE and CE1 CSN with SPI Speed @ 8Mhz
RF24 radio(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ);  

RF24Network network(radio);

// Address of our node in Octal format (01,021, etc)
const uint16_t this_node = 02;

// Address of the other node
uint16_t nodeID = 22; // default nodeID to send command to
int32_t cmd = 01; // default command is to toggle lights

int main(int argc, char** argv) 
{
	// Shell argument action
	int32_t temp1, temp2;
	if (1==sscanf(argv[1], "%d", &temp1))
    	{
		nodeID = temp1; // Ready  input command for sending
	}
	else {
   	       printf("Couldn't understand input!");
 	}
        if (1==sscanf(argv[2], "%d", &temp2))
        {
                cmd = temp2; // Ready  input command for sending
	}
        else {
               printf("Couldn't understand input!");
        }


	// Refer to RF24.h or nRF24L01 DS for settings
	radio.begin();
	
	delay(5);
	network.begin(/*channel*/ 90, /*node address*/ this_node);
	radio.setRetries(5,15);
	radio.setPALevel(RF24_PA_HIGH);
	radio.setDataRate(RF24_250KBPS);
	//radio.printDetails();
	
		network.update();
    		printf("Sending ..");
		RF24NetworkHeader header(/*to node*/ nodeID);
		bool ok = network.write(header,&cmd,sizeof(cmd));
		        if (ok){
		        	printf("ok.\n\n");
		        }else{ 
      				printf("failed.\n");
  			}
	return 0;
}

