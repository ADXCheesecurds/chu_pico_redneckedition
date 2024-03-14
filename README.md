# Chu Pico - Chunithm Style Mini Controller
The original guide: https://github.com/whowechina/chu_pico
## Introduction
This guide is based on the chu_pico project, the only difference is that if you don't/want to build one with a PCB then this guide is for you 
**THIS GUIDE IS ADHD-PROOF AND IS VERY EASY TO FOLLOW, IF YOU MANAGE TO SCREW UP IT IS ON YOU.
## Precautions
* **Some retards at Adafruit or whatever company that made the mpr121 PCB board decided that it's a good idea to pre-short the ground and the address,
so cut it off by making an insertion right here, with a knife or whatever pointy object you have.**
# CUT THE BLACK LINE DON'T CUT ANYONE ELSE. IF YOU DO IT IS DEAD.
<img src="doc/Cutter.png" width="80%">

* **(A)** **Some retards at a Chinese company manufacturing the time of flight sensors didn't update the hardware address or have a faulty address that doesn't work with the Chu_Pico software (for some reason)
make sure to replace it or update the firmware (DON'T ACTUALLY UPDATE THE FIRMWARE THAT IT'S IMPOSSIBLE FOR THE AVERAGE JOE).**

## **WHAT YOU WILL NEED**
* 3X MPR121
* 5X VL53L0X **(THIS IS THE TIME OF FLIGHT SENSOR REFER TO (A) ABOVE**
* Raspberry Pi Pico **(Don't get the W version)**
* TCA9548A/PCA9548A **(
* Aluminium Foil (Best to use Copper tape) 
* A Soldering Kit (optional) **IF YOU ARE NOT USING ONE USE TAPE OR SOME STRONG GLUE**
* Tape
* Acrylic Sheet (Optional) **The alternative is anything plastic and clear like a clear plastic bag**
* Cardboard (Optional) **This is stretching it a bit but where are you going to place it**

## 1. Copper Tape lanes
You will have 4 copper/aluminum tape lanes, One is SDA, SCL, GND, and 3.3V power. Make sure they are not touching and label it or else your dementia ass brain will forget.
**Connect to your Raspberry Pi Pico:**
* **SDA TO GP16**
* **SCL TO GP17** 
* **POWER TO 3V3_OUT** ***DON'T DO 3V3_EN***
* **GROUND TO GND** *COULD BE ANY ACCORDING TO THE PINOUT* 
**HERE IS THE PINOUT DO IT ACCORDINGLY**
  <img src="doc/Pinout.png" width="80%">
## 2.
