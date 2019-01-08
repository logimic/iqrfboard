# Examples with IQRFBB-10

![](files/images/iqrfboardSystem.png)

# Standard Things

Standard things have pre-defined JSON API and all IQRF gateways know them.  If you implement your device in TR module as **Standard Light**, **Standard Binary Output**, **Standard Sensor** and more you have ensured compatibility of your device with IOT world.

## 1. Light
![](files/images/iqrfboard_120x100.png)

This example shows how to create "Standard light" from your board which means that entire world will know that your device is just a light and will be able to manage it (turn on/off, dim, get status and more). Your hardware design on the top of board is not limited.
[Enter example...](examples/example-standardLight/README.md)

## 2. Binary Output
![](examples/example-standardBinOutput/example-standardBinOutput-120x90.png)

This example shows how to create one or more standard binary outputs on the board.
[Enter example..](examples/example-standardBinOutput/README.md)

## 2. Bi-stable Relay
![](files/images/iqrfboard_120x100.png)

This example shows how to manage bi-stable relay on board via standard messages.
[Enter example..](examples/example-standardBistableRelay/README.md)

## 3. Photorezistor Sensor
![](examples/example-standardPhotorezistor/photorezistor_120x90.png)

This example shows how to create standard photorezistor sensor.
[Enter example..](examples/example-standardPhotorezistor/README.md)

## 4. Thermistor Sensor
![](examples/example-standardThermistor/thermistor_120x90.png)

This example shows how to create standard thermistor sensor.
[Enter example..](examples/example-standardThermistor/README.md)

# Pure DPA messages

## 1. Digital Output
![](examples/example-do/example-do-120x90.png)

This example shows how to set HI/LO digital output. The DO has connected external LED.
[Enter example..](examples/example-do/README.md)

## 2. Digital Input
![](examples/example-di/example-di-120x90.png)

This example explains how to detect digital input on board PIN.
[Enter example...](examples/example-di/README.md),

## 3. Hall Magnetic Sensor
![](examples/example-hall/example-hall-120x90.png)

[/example-hall](examples/example-hall/README.md), this example shows how to connect Hall Magentic Sensor with the board and detect event.

## 4. Motion detection (ePir)
![](examples/example-ePir/epir-120x90.png)

[/example-ePir](examples/example-ePir/README.md), this example shows how to connect motion sensor ePir to the board and detect event.

## 5. Bi-stable relay on board
![](files/images/iqrfboard_120x100.png)

[/example-bistable-relay](examples/example-bistable-relay/README.md), this example shows how to switch bi-stable relay on board.

## 6. HTU21D - Temp & Humidity
![](examples/example-HTU21D/HTU21D-120x90.png)

Comming soon HTU21D...

[/example-HTU21D](example-HTU21D), this example shows how to connect HTU21D Temperature and Humidity sensor to board.

## 7. GY-BME280 - Temp & Baro
![](examples/example-GY-BME280/GY-BME280-120x90.png)

Comming soon GY-BME280...
<!--
[/example-GY-BME280](example-GY-BME280), this example shows how to connect GY-BME280 Temperature and Barometric pressure sensor to board.
-->

## 8. Ambient Light Sensor
![](examples/example-GY-49/GY49-120x90.png)

Comming soon GY49...
<!--
[/example-GY-49](example-GY-49), this example shows how to connect GY-BME280 Temperature and Barometric pressure sensor to board.
-->

# IQRF Embedded things

## 1. LED2, LED3 on board
![](files/images/iqrfboard_120x100.png)

First hello world example which turns on/off RED and GREEN diods on the IQRFBB-10 board.
[Enter example...](examples/example-led23/README.md)
