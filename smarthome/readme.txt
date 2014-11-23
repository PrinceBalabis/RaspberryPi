Make server launch at boot:
chmod 755 launcher.sh
cd
mkdir logs
sudo crontab -e
	@reboot sh /root/RaspberryPi/smarthome/launcher.sh >/root/logs/cronlog 2>&1
sudo reboot
