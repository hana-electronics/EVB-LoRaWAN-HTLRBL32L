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
|[template project](/examples/template_project)| Template para começar um projeto do zero |
|[helloWorld](/examples/helloWorld)|Exemplo que escreve HelloWorld via UART|
|[blinking LED](/examples/blinking_LED)| Exemplo de pisca LED |
|[LoRaWAN Base](/examples/LoRaWAN_Base)| Projeto base para uma aplicação que utilizará LoRAWAN|
|[pushButton LoRaWAN](/examples/pushButton_LoRaWAN)| Exemplo que utiliza um botão para enviar pacotes LoRaWAN|
|[pushButton LoRaWAN LowPower](/examples/pushButton_LoRaWAN_LowPower) |Exemplo anterior mas que entra em Sleep Mode|
|[LoRaWAN ADC RTC](/examples/LoRaWAN_ADC_RTC)|Exemplo que mede a tensão ADC na porta PB1 e envia um HelloWorld por LoRaWAN| 
|[pushButton LoRaWAN BLE](/examples/pushButton_LoRaWAN_BLE)| Exemplo que utiliza do Bluetooth para escrever e enviar pacotes LoRaWAN| 
|[Lora P2P](/examples/Lora_P2P) |Exemplo de comunicação peer-to-peer via rádio LoRa|
<br>

## Estrutura de Diretórios
```
├─ Firmware
│   ├── HTLRBL32L-SDK
│   ├── applications
|   |    ├── template_project
|   |    ├── helloWorld
|   |    ├── blinking_LED
|   |    ├── LoRaWAN_Base
|   |    ├── pushButton_LoRaWAN
|   |    ├── pushButton_LoRaWAN_LowPower
|   |    ├── LoRaWAN_ADC_RTC
|   |    ├── pushButton_LoRaWAN_BLE
|   |    └── LoRa_P2P
|   ├── doc
|   |    └── lorawan-keys-apps.pdf
└── README.md
```
## Documentação

Para mais informações sobre esse projeto acessar a seção de [Documentação](https://github.com/Hana-Electronics/EVB-LoRaWAN-HTLRBL32L/tree/master/Firmware/doc).

