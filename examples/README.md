# Important info
Check the README of each example to verify which SDK version is compatible with it.

The SDK is available in its own [repository](https://github.com/Hana-Electronics/HE-HTLRBL32L-SDK). Please check it for updated versions, changelogs, and release notes.

## Clone this branch
```
git clone --single-branch --branch main https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L.git
```

## Examples
Below are some examples to get started with using the EVB LoRa.

| Example     |      Description                    | SDK                   |
| :---------- | :---------------------------------- | :-----------------------|
|[TemplateProject](/examples/TemplateProject)| Template to start a project from scratch. | 1.x.x |
|[HelloWorld](/examples/HelloWorld)| Example that writes HelloWorld via UART. | 1.x.x |
|[BlinkingLED](/examples/BlinkingLED)| Example of blinking LED. |  1.x.x |
|[LoRaWANBase](/examples/LoRaWANBase)| Base project for an application that will use LoRaWAN. | 1.x.x |
|[PushButtonLoRaWAN](/examples/PushButtonLoRaWAN)| Example that uses a button to send LoRaWAN packets. | 1.x.x |
|[PushButtonLoRaWANLowPower](/examples/PushButtonLoRaWANLowPower) |Previous example but goes into Sleep Mode. | 1.x.x |
|[LoRaWANADCRTC](/examples/LoRaWAN_ADC_RTC)| Example that measures ADC voltage on port PB1 and sends HelloWorld via LoRaWAN. | 1.x.x |
|[PushButtonLoRaWANBLE](/examples/PushButtonLoRaWANBLE)| Example that uses Bluetooth to write and send LoRaWAN packets. | 1.x.x |
|[LoraP2P](/examples/LoRaP2P) |Example of peer-to-peer communication via LoRa radio. |1.1.0|

## Directory structure
```
├─ Firmware
│   ├── HTLRBL32L-SDK
│   ├── applications
|   |    ├── TemplateProject
|   |    ├── HelloWorld
|   |    ├── BlinkingLED
|   |    ├── LoRaWANBase
|   |    ├── PushButtonLoRaWAN
|   |    ├── PushButtonLoRaWANLowPower
|   |    ├── LoRaWANADCRTC
|   |    ├── PushButtonLoRaWANBLE
|   |    └── LoRaP2P
|   ├── doc
|   |    └── lorawan-keys-apps.pdf
└── README.md
```