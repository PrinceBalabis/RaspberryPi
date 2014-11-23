#!/bin/bash
if ping -c 1 192.168.1.2
then
  echo "Ping success"
else
  echo "Ping fail"
fi

