# DC-Motor-Control-TLE94112EL Library 

[![Build Status](https://travis-ci.org/Infineon/24V_SHIELD_BTT6030.svg?branch=master)](https://travis-ci.org/Infineon/24V_SHIELD_BTT6030)


<img src="https://github.com/Infineon/Assets/raw/master/Pictures/24V_SHIELD_BTT6030_Shield.png" style="max-width:100%;" width="400">


Library of Infineon's [24V Protected Switch Shield with BTT6030-2EKA and BTT6020-1EKA](https://www.infineon.com/cms/en/product/evaluation-boards/24v_shield_btt6030/) for Arduino.

## Summary
The 24V Protected Switch Shield with BTT6030-2EKA and BTT6020-1EKA is a power switch evaluation board compatible with Arduino microcontroller boards and with Infineon’s XMC™ microcontroller kits using the Arduino form factor. The shield is equipped with three PROtected high-side power MOSFETs out of the PROFET™+ 24V family (2x BTT6030-2EKA , 1x BTT6020-1EKA ) offering five 24 V channels in total. Infineon’s PROFET™+ 24V protected high-side switches (BTT6xxx) drive resistive, capacitive as well as inductive loads (e.g. truck bulbs, car bulbs, valves, motors, relays, capacitors, LEDs…). The power switches are controlled via the INx (input) pins. The PROFET™+ 24V devices also provide a sense current at the IS pin, which can be enabled via the DEN (Diagnosis ENable) pin. For the two channel devices the sensed channel is selected via the DSEL (Diagnosis SELect) pin. For each device the sense signal (IS) is connected to an own ADC channel of the microcontroller.

## Key Features and Benefits
* Compatible with Arduino microcontroller boards and Infineon’s XMC™ microcontroller kits using the Arduino form factor
* Capable of PWM up to 400 Hz
* Driver circuit with logic level inputs
* Diagnosis with current sense
* Protection of load and driver circuit e.g. against overtemperature, overcurrent, ESD
* Fast and inexpensive prototyping of 24 V load driving
* Load diagnosis with current sense capability
* Overtemperature shut down with latch behavior


## Target Applications:
* Drive resistive, capacitive and inductive loads with PWM or DC
* 8 ~ 36 V nominal input voltage (max. 5 ~ 48 V)
* Nominal current up to 5 A per channel restricted due to PCB (BTT6020-1EKA nominal current: 7 A)
* E.g. truck bulbs, valves, motors, relays ...

## Installation
For the description of library [installation](docs/Installation.md)

## Examples
For the description of the [examples](docs/Examples.md)

## Library documentation
The doxygen [library documentation](https://infineon.github.io/24V_SHIELD_BTT6030/).

## More information and links
* [Infineon Maker page](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/#overview)
* [Infineon Microcontroller](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/microcontroller-boards/)
* [Infineon Shields for Arduino](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/arduino-shields/)
* [Quickstart](https://www.infineon.com/dgdl/Infineon-PROFET+-24V-Shield-for-Arduino_Quick%20Start-Guide_A6.pdf-GS-v01_00-EN.pdf?fileId=5546d46255dd933d015601ebe4152ad0)
* [User manual](https://www.infineon.com/dgdl/Infineon-24V_ProtectedSwitchShield_with_Profet+24V_for_Arduino_UsersManual_10.pdf-UM-v01_00-EN.pdf?fileId=5546d46255dd933d0156074933e91fe2)
* [Eagle PCB data](https://www.infineon.com/dgdl/Infineon-PROFET+_24V_Shield_wo_OL_V1.2_PCB_DATA_Eagle_V1.2.zip-ATI-v01_02-EN.zip?fileId=5546d4625607bd130156080989463b07)
* [Pinout picture](https://github.com/Infineon/Assets/raw/master/Pictures/24V_SHIELD_BTT6030_Shield_pinout.png)



