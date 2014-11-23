#!/usr/bin/env python
"""
Most of this code comes from aweinstein, THANK YOU
https://github.com/aweinstein/scrapcode/blob/master/post_server/server.py

Very simple HTTP server in python.

Usage::
    ./dummy-web-server.py [<port>]

Send a GET request::
    curl http://localhost

Send a HEAD request::
    curl -I http://localhost

Send a POST request::
    curl -d "foo=bar&bin=baz" http://localhost

"""
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import SocketServer
import os

class S(BaseHTTPRequestHandler):
    def _set_headers(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        self._set_headers()
        self.wfile.write("<html><body><h1>Hi! You just ran homeautomation!</h1></body></html>")

    def do_HEAD(self):
        self._set_headers()
        
    def do_POST(self):
        self._set_headers()
	content_length = int(self.headers['Content-Length'])
	post_data = self.rfile.read(content_length)

	#Check if you are entering or exiting the iBeacon area
	action = "Didn't understand command!"
	returnmessage = "Didn't understand command!"
	if post_data[76] == 'x':
                returnmessage = "You just exited the iBeacon area!"	
		action = "./sendRF24Command 03"
	elif post_data[76] == 'n':
	        returnmessage = "You just entered the iBeacon area!"			
                action = "./sendRF24Command 02"

	#Print action feedback
	self.wfile.write("<html><body><h1>"+returnmessage+"</h1></body></html>")
	print returnmessage

	#Run shell command
	def main():
                os.system(action)
        if __name__=="__main__":
                main()

def run(server_class=HTTPServer, handler_class=S, port=4050):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print 'Started iBeacon Smart Home Server'
    httpd.serve_forever()

if __name__ == "__main__":
    from sys import argv

    if len(argv) == 2:
        run(port=int(argv[1]))
    else:
        run()

