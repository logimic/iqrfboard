# Standard Light

This example shows how to create "Standard light" which means that entire world will know that your device is just a light and will be able to manage it (turn on/off, dim, get status and more). This is possible thanks to standardized API and IQRF gateways.

Standardization does not limit your hardware creativity, your light can be whatever you connect. The software in TR module makes connection with API.

In following we will show how to implement three lights on the one board. The lights will be LED2, LED3 and external LED on SCL/EQ6 PIN.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [Getting Started](../../README.md)
2. **IQRF Gateway Daemon** working. More in [IQRF Gateway Daemon](../../IqrfGatewayDaemon.md)
3. **Python 3.6 with WebSockets module**. More in [Python WebSockets example](../../IqrfGatewayDaemon.md#python-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

![](standard-light_bb.png)

Connect external LED to SCL/EQ6 PIN.

## Software in TR module

The [standard-light.c](https://github.com/logimic/iqrfboard/blob/master/examples/standard-light.c) implements three lights on LED2, LED3 and SCL/EQ6 outputs.
Please load this "Custom DPA Handler" to TR module on board. [Load Custom DPA Handler](../../SetupIqrfNetwork.md#load-custom-dpa-handler) manual.

## API JSON message

Since we implemented standard light we can use standardized JSON messages for [management of Lights](https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html#light) via JSON API of gateways.

## Testing Python code

The [standard-light.py](https://github.com/logimic/iqrfboard/blob/master/examples/standard-light.py) does:

- LED3=ON
- LED3=OFF, LED2=ON
- LED2=OFF, ext. LED=ON
- ext. LED=OFF
