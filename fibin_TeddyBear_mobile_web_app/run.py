import RPi.GPIO as GPIO
import time
import os

#adjust for where your switch is connected
buttonPin = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(buttonPin,GPIO.IN)
prev_input = 0

while True:
  input = GPIO.input(buttonPin)
  if ((not prev_input) and input):
	print("Button Pressed")
	prev_input = input
	time.sleep(0.05)


#while True:
  #assuming the script to call is long enough we can ignore bouncing
 #if (GPIO.input(buttonPin)):
    #this is the script that will be called (as root)
  #  print("Button Pressed")
   # time.sleep(0.20)
  #  os.system("home/pi/node/node-v0.10.2-linux-arm-pi/bin/node -v")
#    os.system("bash /home/pi/master-fibinButtons/run.sh")
