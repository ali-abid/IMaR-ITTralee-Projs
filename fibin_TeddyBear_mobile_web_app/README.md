#How to install Fibin Teddy Bear mobile web application on RaspberryPi?

##Download nginx on RaspberryPi
source: http://www.raspipress.com/2014/06/tutorial-install-nginx-and-php-on-raspbian/

sudo apt-get install nginx


##Download nodejs on RaspberryPi

sudo apt-get install node


##Download project into RaspberryPi.  

e.g. home/pi/fibin_TeddyBear_mobile_web_app  

source: https://github.com/ali-abid/IMaR-ITTralee-Projs/tree/master/fibin_TeddyBear_mobile_web_app 


##Manually start nginx and nodejs
//Start nginx

sudo /etc/init.d/nginx start  

//Start nodejs

/home/pi/node/node-v0.10.2-linux-arm-pi/bin/node [Give space here] /home/pi/fibin_TeddyBear_mobile_web_app/socket.js

##Auto start nginx and nodejs on RaspberryPi boot up

sudo crontab –e  //Type in RaspberryPi terminal


// Write following two lines at the end of crontab file

@reboot sh home/pi/fibin_TeddyBear_mobile_web_app/run.sh  >/home/pi/logs/anyName1  2>&1 

@reboot sh home/pi/fibin_TeddyBear_mobile_web_app/espeak/sayIPbs.sh  >/home/pi/logs/anyName2  2>&1 

Note: anyName files use for debugging purpose

********************************************************************************************


***************************************************************************
#How to run Application?

##Step 1: Connect wifi Edimax

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


##Step 2: Connect Smart Phone on same wifi network

//Power up RaspberryPi and it will speak IP address and Port number 

//Type IP address and port number in your smart phone browser

    XXX.XXX.XXX.XX:8081

****************************************************************************


