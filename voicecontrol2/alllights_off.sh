#!/bin/bash
/root/RaspberryPi/433mhz/send 5525844 && RaspberryPi/433mhz/send 5510484 && tts 'All lights off!' 2>/dev/null && curl --data-binary '{ "jsonrpc": "2.0", "method": "GUI.ShowNotification", "params":{"title":"J.A.R.V.I.S.","message":"All lights off!"},"id":1 }' -H 'content-type: application/json;' http://balabis:balabis1234@127.0.0.1:9453/jsonrpc 
