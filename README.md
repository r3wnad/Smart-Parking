# Smart-Parking
## Project Statement
A smart parking system with IoT using both Arduino and Node MCU. Enabled cloud update of availability of parking slots.

## Components
1 Arduino MEGA 2560 board, 1 Node MCU, 1 HC-SRO4 ultrasonic sensor, [1 LCD display](#LCD), 2 FC-51 IR modules, 2 SG-90 servo motors, 1 Potentiometer, 1 Breadboard, Several jumper-wires

## Specifications
### HC-SR04 Ultrasonic Sensor
Working Voltage: DC 5V,
Working Current: 15mA,
Working Frequency: 40Hz,
Min Range: 2cm,
Max Range: 4m,
Measuring Angle: 15°.

**Pin-out**

VCC: *Power*, GND: *Ground*, TRIG: *trigger output*, ECHO: *echo input*

### LCD 
Operating voltage:	5±0.3V DC,
Operating current: 1mA (without backlight),
Controller:	Hitachi HD44780 LCD controller,
Screen resolution:	2 lines x 16 characters,
Character resolution:	5 x 8 pixels

**Pin-out**
 Pin no. | Label | Connection	| Function 
---|---|---|---
 1 | VSS | GND | Signal ground 
2 | VDD | 5V | Logic power for LCD 
3	| V0 | 10 kΩ potentiometer |	Contrast adjustment
4	| RS	| Pin 41 | Register select signal
5	| R/W	| GND |	Read/write select signal (grounded to write)
6	| E	| Pin 39 | Operation enable signal
7–14 | D0 – D7 |	| Data bus lines used for 8-bit mode
11-14 |	D4 – D7	| Pin 37, 35, 33, 31 |	Data bus lines used for 4-bit mode
15 | A (LED+) |	5V | Anode for LCD backlight
16 | K (LED-)	| GND | Cathode for LCD backlight

### FC-51 IR Sensor

Detection angle: 35 °,
Operating Voltage: 3.0V – 6.0V,
Current Consumption: at 3.3V : ~23 mA, at 5.0V: ~43 mA,
Detection range: 2cm – 30cm (Adjustable)

**Pin-out**

VCC: _3.3V-5V_, GND: _Ground_, OUT: _Digital Output Pin_

### SG90 Servo Motor

Operating Voltage: DC 4.8-6V,
Operating Speed (4.8V): 0.15 Seconds/60°,
Operating Speed (6V): 0.12 Seconds/60°,
Stall Torque (4.8V): 1.3kg/cm,
Stall Torque (6V) : 1.5kg/cm,
Rotation: 0°-180°,
Gear Type: Plastic.

**Pin-out**

Red Colour- _Supply_,
Orange Colour- _PWM (Signal)_,
Brown Colour- _GND_.

## Breadboard Layout

![image](Fritzing/Smart%20parking_bb.png)
