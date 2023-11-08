# Blinking LED

This project blinks the in-board LED with a small delay. 

The firmware configures some necessary peripherals, like USART1 (log purposes) and GPIOs (radio interruption, etc.).

## SDK Version
This example is compatible with version 1.x.x.  

The SDK is available in its own [repository](https://github.com/Hana-Electronics/HE-HTLRBL32L-SDK). 

## Before you start

The tutorial below is only applicable if you're flashing the EVB with an ST-LINK, you can't flash it directly with a USB-C. If you're using a USB-C cable you'll need to flash it via [bootloader](/docs/Bootloader.md).

# Executing														  
1. Clone the examples branch: <br/>

```
git clone --single-branch --branch main https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L.git
```

2. Open WiSE-Studio IDE. 
3. Click in "File->Open Projects from File System...": <br/>

<div align="center">
  <img src="/docs/images/wiseopenproj1.jpg">
</div>

<br/>

4. Click in "Directory...", find and select your cloned folder "Blinking LED then click "Finish" to open project. <br/>

<div align="center">
  <img src="/docs/images/wiseopenproj2.jpg">
</div>

<br/>

5. Right click the project in the project explorer, then click "Run As...-> Wise C/C++ Application" to build and flash the new firmware into your device: <br/>

<div align="center">
  <img src="/docs/images/run.jpg">
</div>

<br/>

6. Open Termite and reset your device to check what was printed on serial. Also check the LED on the Board, it must be blinking <br/>

<div align="center">
  <img src="/docs/images/Blinking%20LED.png">
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
