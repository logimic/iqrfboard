# Standard Thermistor Sensor

This example shows how to create "Standard Thermistor Sensor" that will be immediately recognized and manageable from IOT world thanks to gateways and standardization.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [Getting Started](../../README.md)
2. **IQRF Gateway Daemon** working. More in [IQRF Gateway Daemon](../../IqrfGatewayDaemon.md)
3. **Python 3.6 with WebSockets module**. More in [Python WebSockets example](../../IqrfGatewayDaemon.md#python-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

![](standard-thermistor_bb.png)

Photorezistor is connected to GND, VCC and Q9(SS)/C5/AN4.

## Software in TR module

The [standard-thermistor.c](https://github.com/logimic/iqrfboard/blob/master/examples/standard-thermistor.c) implements one binary input.
Please load this "Custom DPA Handler" to TR module on board. [Load Custom DPA Handler](../../SetupIqrfNetwork.md#load-custom-dpa-handler) manual.

## API JSON message

Since we implemented standard sensor we can use all standardized JSON messages for [Sensor ](https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html#sensor) via JSON API of gateways.

## Testing Python code

The [standard-thermistor.py](https://github.com/logimic/iqrfboard/blob/master/examples/standard-thermistor.py) does following:

- Gets number of implemented standard sensors in TR module.
- Reads sensor in loop of 200 measurements
- Displays measured value from JSON message
