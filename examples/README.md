# Important info
Check the README of each example to verify which SDK version is compatible with it.

The SDK is available in its own [repository](https://github.com/Hana-Electronics/HE-HTLRBL32L-SDK). Please check it for updated versions, changelogs, and release notes.

## Clone this branch
```
git clone --single-branch --branch main https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L.git
```

## Exemplas
Below are some examples to get started with using the EVB LoRa.

| Example  |      Description                  | 
| :---------- | :---------------------------------- | 
|[TemplateProject](/examples/TemplateProject)| Template to start a project from scratch. |
|[HelloWorld](/examples/helloWorld)| Example that writes HelloWorld via UART. |
|[BlinkingLED](/examples/BlinkingLED)| Example of blinking LED. |
|[LoRaWANBase](/examples/LoRaWANBase)| Base project for an application that will use LoRaWAN. |
|[PushButtonLoRaWAN](/examples/PushButtonLoRaWAN)| Example that uses a button to send LoRaWAN packets. |
|[PushButtonLoRaWANLowPower](/examples/PushButtonLoRaWANLowPower) |Previous example but goes into Sleep Mode. |
|[LoRaWANADCRTC](/examples/LoRaWAN_ADC_RTC)| Example that measures ADC voltage on port PB1 and sends HelloWorld via LoRaWAN. |
|[PushButtonLoRaWANBLE](/examples/PushButtonLoRaWANBLE)| Example that uses Bluetooth to write and send LoRaWAN packets. |
|[LoraP2P](/examples/LoRaP2P) |Example of peer-to-peer communication via LoRa radio. |
<br>

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
## Documentação

Para mais informações sobre esse projeto acessar a seção de [Documentação](https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L/tree/master/Firmware/doc).

