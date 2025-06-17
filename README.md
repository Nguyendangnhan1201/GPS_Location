# Project: _GPS_Location_
## Overview: 
This is an arduino project in which Module GPS 6M V2 is combined with LCD 1602 module. The project aims to display Latitude and Longtitude values onto the LCD screen as well as setting the alarm when the signal is recieved. 
## Materials:
1 Arduino board (I used Arduino UNO R3), 1 LCD 1602 and an I2C, 1 Module GPS 6M V2, 1 buzzer, wires. 
## Libraries to be downloaded for the project: 
1. <TinyGPS++.h>           
2. <SoftwareSerial.h>
3. <LiquidCrystal_I2C.h>
4. <Wire.h>
## Connection instruction:
1. In this project, the LCD is equipped with an Ì2C, the I2C pins must be connected to the SPI pins of arduino board (SDA and SCL pins).
2. Module GPS: The board with TX and RX pins should be connected to pins numbered 3 and 4 of arduino board (it is easier compared to connecting to pin 0 and 1).
3. Buzzer: The buzzer can be set to connect to a digital pin (as in my project) or an analog pin.
## Notes:
1. It is advisable that the components and the arduino board are connected to the right voltage sources.
2. I highly recommend  using reliable libraries from Github. Once you have downloaded the zip files of the libraries, you should install it through Arduino IDE.
3. It may take a little time to connect to satellites and recieve values. In order to make the connection easier, the GPS Module should be placed outdoors.
4. The project can also be developed to receive time, altitude,... through GPS Module if you want.
