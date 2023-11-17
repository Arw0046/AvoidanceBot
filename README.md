# AvoidanceBot
Simple autonomous obstacle avoidance robot

# Intro
Welcome! This is repo is for an autonomous robot that can avoid obstacles infront of it, and will contain all the software and hardware, along with a guided walkthrough of everything to set it up. Now i would like to give a brief description of everything the robot does. The robot will first send out a soundwave and wait for it to make its way back. It will then calculate the distance it travelled and determine if an obstacle is within 20cm in front of it. Based on this determination, the robot will continue to drive foward if its greater than 20cm or stop for a second and turn left. As you can probably guess, this robot doesnt require much to get up and running. I have made a section labeled "Hardware" that lists all of the required tools, a section labeled "Schematic" for the cuircuit hook-up, and a video to give an idea of what the final product will look like and how it behaves. I will also be including all of the software that is needed to get this project running. Besides the program, you will need a way to compile the code and send it off into a microcontroller. All of the tools needed for this will be listed in the folder labeled "TOOLCHAIN". Now, onto the hardware...

# Hardware
* 1 Microcontroller (Atmega328P)
* 1 AVR Programmer (sparkfun pocket avr programmer) 
* 1 usb A to mini usb 2.0 cable 
* 1 PC (nothing special here, any laptop/PC should work. preferably with windows installed as thats what I used for this project) 
* 1 robot car kit (this is the specific kit I used, any kit that contains a chassis, 2 tires, 2 dc motors, 1 universal wheel, and 1 battery box(around 5-6v) will do.) https://www.amazon.com/perseids-Chassis-Encoder-Wheels-Battery/dp/B07DNYQ3PX/ref=sr_1_8?crid=HA54V6DZ00U5&keywords=arduino%2Bcar%2Bchassis&qid=1697843578&-sprefix=arduino%2Bcar%2Bchassis%2Caps%2C134&sr=8-8&th=1 
* 1 motor driver (L298N) 
* 1 9v battery 
* 1 9v battery holder
* 2 half size breadboards 
* 1 ultra sonic sensor (HC-SR04) 
* assortment of wires 
* 1 10 uF capacitor 
* 1 10kohm resitor 
* 1 wire strippers 
* 1 wire cutters

# Schematic

# Guide
1. The first thing you will need to do is to download everything in this repo. I highly recommend downloading everything all in its own folder.
2. Right click on the file called AVRGCCStart, and select edit with notepad++. Everywhere you see "yourpath", replace with the path you created in step one(dont delete everything after "yourpath"!)
3. Hookup your atmega328p to your computer and double click on AVRGCCStart.
4. Change directory to the robot folder. To do this, type cd C:\"yourpath"\AvoidanceBot\ROBOT\robot. Then hit enter(make sure to change "yourpath")
5. Type make flash, this will flash the program into your mcu.
6. Now hook-up everything as described in the Schematic section.
7. Now Test it out!
