Compile server using:
g++ -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -Wall -I../libraries/NRF24NetworkPi -lrf24-bcm -lrf24network sendRF24Command.cpp -o sendRF24Command
