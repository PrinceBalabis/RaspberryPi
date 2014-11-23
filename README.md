#RaspberryPi Various projects
git clone https://github.com/PrinceBalabis/RaspberryPi.git    
cd RaspberryPi

##433mhz
Program to open or close 433mhz radio switches using a 433mhz transmitter    
Modified from original source.
More information:
http://www.princetronics.com/voice-controlling-wireless-switches-using-raspberry-pi/

##basicvoicecontrol
Basic voice control program to run specific shell commands, scripts or ask wolframalpha questions using voice commands.    
Modified from original source.

##stresstest
Stresstest program for Raspberry Pi
From original source

##voicecontrol2
Instructions for a more advanced voice control than basicvoicecontrol. Can do anything basicvoicecontrol can, but can also start listening for command when said a specific keyword and has a lot more random features.    
Only instructions to setup from original source.
More information:
http://www.princetronics.com/voice-controlling-wireless-switches-using-raspberry-pi/

##iBeaconHomeAutomation
Turn on/off things like lights, speaker, PC, kitchen appliances etc when entering/leaving home(or an area) - using iBeacon technology
Minimal Hardware requirements:
-iPhone with iBeacon capability(Bluetooth LE)
-Raspberry Pi(
-Some iBeacon device running in the area(USB module, chip module, virtual etc)

Other hardware used in this project:
-nRF24L01+ wireless transceiver modules
-Arduino

Software Requirements:
-GeoHopper app

How it works:
When your iPhone enters an iBeacon area, the iPhone detects the iBeacon, 
and the GeoHopper app send a GET to the Raspberry Pi, which is running a
Python webserver. When the webserver gets the GET from your iPhone, it
runs the code to do whatever you want(switch LEDs, lights, relays...
In my case it send a wireless signal using nRF24L01, modules to my Arduinos
around my apartment, acting as IOTs - Internet Of Things, telling them to turn on/off whatever theyre connected to, like my apartment lights )

Why use iBeacon for home awareness?
You could use PIR modules for detecting whenever you enter your home(or area),
but how would your home know whether you enter or leave your home? 
You could probably write logic for this, and/or use several PIR positioned around,
but its a lot easier just using iBeacon, and letting
you iPhone tell your apartment whenever it knows you left the apartment.
At first I was thinking of the possibility of letting your Raspberry Pi keep
networking pinging your phone's IP-address to check if your phone is home,
but then i realized my iPhone disables the WiFi module whenever after it has been sleeping
a while. So even if you were home, but not using your phone, the Raspberry Pi would think
you are not and toggle the lights. iBeacon is the ultimate answer! Easy implementation,
not a single move needed to turn on your PC, monitors, speakers and lights when you get home!

Why use Python for this?
I usually don't write Python, but Google begged me to use it for this project.
Python has EVERYTHING I needed for this project and implements everything really easily.
It can run a webserver, run shell commands, and a lot other stuff.
