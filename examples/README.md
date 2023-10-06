# Firmware
Esta área contém arquivos referentes ao firmware do projeto, assim como o [SDK](https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L/tree/master/Firmware/HTLRBL32L-SDK) do SIP.
<br>
<br>

## Como clonar este branch
```
git clone --single-branch --branch main https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L.git
```

## Exemplos
Abaixo encontra-se alguns exemplos para iniciar o uso da EVB LoRa.

| Aplicação  |      Descrição                      | 
| :---------- | :---------------------------------- | 
|[TemplateProject](/examples/TemplateProject)| Template para começar um projeto do zero |
|[HelloWorld](/examples/helloWorld)|Exemplo que escreve HelloWorld via UART|
|[BlinkingLED](/examples/BlinkingLED)| Exemplo de pisca LED |
|[LoRaWANBase](/examples/LoRaWANBase)| Projeto base para uma aplicação que utilizará LoRAWAN|
|[PushButtonLoRaWAN](/examples/PushButtonLoRaWAN)| Exemplo que utiliza um botão para enviar pacotes LoRaWAN|
|[PushButtonLoRaWANLowPower](/examples/PushButtonLoRaWANLowPower) |Exemplo anterior mas que entra em Sleep Mode|
|[LoRaWANADCRTC](/examples/LoRaWAN_ADC_RTC)|Exemplo que mede a tensão ADC na porta PB1 e envia um HelloWorld por LoRaWAN| 
|[PushButtonLoRaWANBLE](/examples/PushButtonLoRaWANBLE)| Exemplo que utiliza do Bluetooth para escrever e enviar pacotes LoRaWAN| 
|[LoraP2P](/examples/LoRaP2P) |Exemplo de comunicação peer-to-peer via rádio LoRa|
<br>

## Estrutura de Diretórios
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

