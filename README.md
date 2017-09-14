# WS2812B-LED-RC-Controller
WS2812B Controller for RC plane night flying with spotlight

#### Fast overview: Video will come soon.

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi//0.jpg)]
(https://www.youtube.com/watch?v=)

## 1.Hardware:
-	Atmel Atmega328p
-	WS2812B stirp (got mine from https://www.banggood.com/5M-45W-150SMD-WS2812B-LED-RGB-Colorful-Strip-Light-Waterproof-IP65-WhiteBlack-PCB-DC5V-p-1035640.html)
-	3W 12V LED
- Transistor 2N3904
- Capacitors - 10uF/25V
- Socket for Atmega
- Some servo wires
- Crystal 16MHz
- Capacitor Ceramic 22pF
- PCB of your choice

## 2.Software:
-	get your isp-programmer (ex. USBasp) working, linux is your friend
-	install latest Arduino IDE and drivers
- install FastLED https://github.com/FastLED/FastLED

## 3.Libraries used in this project:
-	FastLED from https://github.com/FastLED/FastLED

### Installation: 
1. prepare Hardware. Ground to Ground and the rest like the schematics (comming soon).
2. Upload the sketch to the Arduino with the ISP-Programmer.
3. Set the switches on your RC control for the two channels.
7. Power everything up.
8. Enjoy your WS2812B-LED-RC-Controller

Bug and Features: Please report bugs and wishes to me. Thanks!


