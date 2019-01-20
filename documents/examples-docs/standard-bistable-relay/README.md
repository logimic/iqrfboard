# Standard Bi-stable Relay

This example shows how to manage bi-stable relay on board via standard messages. Bi-stable relay is designed on board and is driven by two digital outputs C1 and C0. Relay state is shown via LD5 and LD6 diod.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [Getting Started](../../README.md)
2. **IQRF Gateway Daemon** working. More in [IQRF Gateway Daemon](../../IqrfGatewayDaemon.md)
3. **Python 3.6 with WebSockets module**. More in [Python WebSockets example](../../IqrfGatewayDaemon.md#python-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

No special wiring since the relay is on the board. The state of relay is signalized via LD5 and LD6 or you can connect any external cicuit to relay contacts NC1, COM1, NO1 and NC2, COM2, NO2. See drawings.   

## Software in TR module

The [standard-bistable-relay.c](https://github.com/logimic/iqrfboard/blob/master/examples/standard-bistable-relay.c) implements two binary outputs.
Please load this "Custom DPA Handler" to TR module on board. [Load Custom DPA Handler](../../SetupIqrfNetwork.md#load-custom-dpa-handler) manual.

## API JSON message

Since we implemented standard binary output we can use all standardized JSON messages for [Binary Output ](https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html#binaryoutput) via JSON API of gateways.

## Testing Python code

The [standard-bistable-relay.py](https://github.com/logimic/iqrfboard/blob/master/examples/standard-bistable-relay.py) does following:

- Gets number of implemented binary outputs in TR module.
- 3 times switches state of bi-stable relay.
