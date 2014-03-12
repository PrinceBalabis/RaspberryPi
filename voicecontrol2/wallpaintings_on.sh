#!/bin/bash
/root/RaspberryPi/433mhz/send 5525845 && tts 'Wall painting-lights on!' 2>/dev/null && curl --data-binary '{ "jsonrpc": "2.0", "method": "GUI.ShowNotification", "params":{"title":"J.A.R.V.I.S.","message":"Wall painting-lights on!"},"id":1 }' -H 'content-type: application/json;' http://balabis:balabis1234@127.0.0.1:9453/jsonrpc
