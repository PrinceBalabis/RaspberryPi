backup using this command:

rsync -avz --exclude-from=/root/RaspberryPi/rsync/rsync-exclude.txt / root@192.168.1.5:/data/NAS/Backups/RaspberryPi



run daily backup using these commands:

crontab -e

@daily  /bin/sleep 300 ; rsync -avz --exclude-from=/root/RaspberryPi/rsync/rsync-exclude.txt / root@192.168.1.5:/data/NAS/Backups/RaspberryPi

