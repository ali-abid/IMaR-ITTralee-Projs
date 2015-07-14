
***************************************************************************
##Run Application:

#Step 1: Connect wifi Edimax

Login to RaspberryPi:
cd /etc/network/ sudo nano interfaces

auto lo
iface lo inet loopback
iface eth0 inet dhcp

allow-hotplug wlan0
auto wlan0

iface wlan0 inet dhcp
   wpa-ssid "Your Network SSID"
   wpa-psk "Your Password"


//Save the file and exit 
Ctrl+O, Ctrl+X.         

//Reboot RaspberryPi
// RaspberryPi speak IP address and port number 8081,
//if connected successfully to wifi network.


#Step 2: Connect Smart Phone on same wifi network

//Power up RaspberryPi and it will speak IP address and Port number 

//Type IP address and port number in your smart phone browser
    XXX.XXX.XXX.X:8081

****************************************************************************


##How to install fibin_TeddyBear_mobile_web_app on RaspberryPi

#Install nginx on RaspberryPi

#Install nodejs on RaspberryPi

#Download https://github.com/ali-abid/IMaR-ITTralee-Projs/tree/master/fibin_TeddyBear_mobile_web_app 
complete folder into your RaspberryPi.  e.g. home/pi/fibin_TeddyBear_mobile_web_app 

#Manually start nginx and nodejs
//Start nginx

/etc/init.d/nginx start

//Start nodejs

/home/pi/node/node-v0.10.2-linux-arm-pi/bin/node  /home/pi/fibin_TeddyBear_mobile_web_app/socket.js

#Auto start nginx and nodejs on RaspberryPi boot up

sudo crontab –e  //Type in RaspberryPi terminal


// Write following two lines at the end of crontab file

@reboot sh home/pi/fibin_TeddyBear_mobile_web_app/run.sh  >/home/pi/logs/anyName1  2>&1 

@reboot sh home/pi/fibin_TeddyBear_mobile_web_app/espeak/sayIPbs.sh  >/home/pi/logs/anyName2  2>&1 

Note: anyName files use for debugging purpose

