# Push button - LoRaWAN and BLE
This application works using the android app GATTbrowser to connected via bluetooth with the device, write the payload and send LoRa packets to the server.

The firmware configures some necessary peripherals, like USART1 (log purposes), GPIOs (radio interruption, etc.) and I2C (STsafe). 

More code details can be found reading the 'Code Notes' section further below and the comments written in all header files available in this application.

## SDK Version
This example is compatible with version 1.x.x.  

The SDK is available in its own [repository](https://github.com/Hana-Electronics/HE-HTLRBL32L-SDK). 

## Test Setup

This section describes the basic test setup to running this application.

* [Git](https://git-scm.com/downloads).
* [RF-Flasher Utility](https://www.st.com/en/embedded-software/stsw-bnrgflasher.html).
* [WiSE-Studio IDE](https://www.st.com/en/embedded-software/stsw-wise-studio.html).
* RS232 terminal ([Termite](https://www.compuphase.com/software_termite.htm) is recommended).
* [ST-Link Debugger](https://www.st.com/en/development-tools/st-link-v2.html) to flash a firmware.
* [GATTbrowser android app](https://play.google.com/store/apps/details?id=com.renesas.ble.gattbrowser).
* EVB - HTLRBL32.
* LoRa® Gateway.
* FTDI (usb-serial converter – one for each device).

# Executing

1. Set your LoRaWAN keys (OTAA and/or ABP): <br/>

If using the ST-SAFE module:							
- Flash the binary "[HTLRBL32L_Provisioner.bin](https://github.com/htmicron/htlrbl32l/tree/SDK/Applications/Binaries)" using "[RF-Flasher Utility](https://www.st.com/en/embedded-software/stsw-bnrgflasher.html)".
- Follow the instructions at the "[HTLRBL32L_Key_Provisioner_Manual](https://github.com/htmicron/htlrbl32l/tree/SDK/Key_Provisioner/Documentation)"
- Save your setted keys to configure the TTN device later.
Otherwise, you may define the LoRaWAN keys in the 'lorawandefines.h' header file after step 5.																							  

2. Clone the examples branch: <br/>

```
git clone --single-branch --branch main https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L.git
```

3. Open WiSE-Studio IDE. 
4. Click in "File->Open Projects from File System...": <br/>

<div align="center">
  <img src="/docs/images/wiseopenproj1.jpg">
</div>

<br/>

5. Click in "Directory...", find and select your cloned folder "PushButton_LoRaWAN_BLE" then click "Finish" to open project. <br/>

<div align="center">
  <img src="/docs/images/wiseopenproj2.jpg">
</div>

<br/>

6. Right click the project in the project explorer, then click "Run As...-> Wise C/C++ Application" to build and flash the new firmware into your device: <br/>

<div align="center">
  <img src="/docs/images/run.jpg">
</div>

<br/>

7. Open Termite and reset your device to check if the initial string was printed on serial. <br/>

<div align="center">
  <img src="/docs/images/termite.jpg">
</div>

<br/>

# Code Notes

-  In the case OTAA is being used, the device will keep sending join requests until it has been able to join the server before entering deep sleep/awaiting user inputs.
-  ST-SAFE is activated by the pre-processor symbol 'HT_CRYPTO'.
-  The 'DEEP_SLEEP_MODE' constant is used to define the behaviour of the SiP when awaiting user input. If disabled, the device will await for the interrupt triggered by the Bluetooth user input. If enabled, the device will enter deep sleep to reduce power consumption, and will only be "woken up" by user input.

# The Things Network (TTN) Configuration

- Create a TTN account at "[TTN website](https://www.thethingsnetwork.org/)" and follow the "[guide](https://www.thethingsnetwork.org/docs/gateways/)" to your gateway. <br/>
- Use the keys you set earlier to add your device in the TTN network.
- [More info](https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L/blob/main/examples/doc/lorawan-keys-apps.pdf)

# GATTbrowser

- Download [GATTbrowser android app](https://play.google.com/store/apps/details?id=com.renesas.ble.gattbrowser).
- Open the app and click to open the PushButton device: <br/>

<div align="center">
  <img src="/docs/images/bledevice.jpg">
</div>

<br/>

- Once the device is connected: <br/>

<div align="center">
  <img src="/docs/images/connected.jpg">
</div>

<br/>

- Click here to go into the read/write page: <br/>

<div align="center">
  <img src="/docs/images/packetpage.jpg">
</div>

<br/>

- You can choose between a string and hexadecimal payload. Write the payload as the picture and click the write button: <br/>

<div align="center">
  <img src="/docs/images/write.jpg">
</div>

<br/>

- You sent this payload via LoRaWAN to your TTN network server. <br/>

<div align="center">
  <img src="/docs/images/lorasent.jpg">
</div>

<br/> 

## Extra Documentation

Datasheets and application notes can be found at [HTLRBL32 Repository](https://github.com/htmicron/htlrbl32l).

## References

For additional information:

* [HTLRBL32 datasheet](https://www.st.com/resource/en/datasheet/hts221.pdf).
* [Semtech SX1308 LoRa® Gateway datasheet](https://www.mouser.com/datasheet/2/761/sx1308-1277867.pdf).


## Contact Information

Head Office – São Leopoldo, RS <br/>
HT Micron Semiconductors <br/>
Unisinos Avenue, 1550 <br/>
São Leopoldo - RS <br/>
ZIP 93022-750 <br/>
Brazil <br/>
Tel: +55 51 3081-8650 <br/>
E-mail (Support): support_iot@htmicron.com.br <br/>
E-mail (General Enquiries): htmicron@htmicron.com.b <br/>