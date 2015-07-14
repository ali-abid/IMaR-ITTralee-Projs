#!/bin/sh
echo  "Start Nginx"
/etc/init.d/nginx start

echo "Node Version"
/home/pi/node/node-v0.10.2-linux-arm-pi/bin/node  -v

echo "Listening on port 8081"

echo "Starting Node..."
/home/pi/node/node-v0.10.2-linux-arm-pi/bin/node  /home/pi/fibinButtons/socket.js

