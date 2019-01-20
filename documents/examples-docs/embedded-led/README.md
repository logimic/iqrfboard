# Embedded LED

This example turns RED LED on, waits 2 seconds, then turns RED LED off and GREEN LED on, then after 2 seconds turns GREEN LED off.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [Getting Started](../../README.md)
2. **IQRF Gateway Daemon** working. More in [IQRF Gateway Daemon](../../IqrfGatewayDaemon.md)
3. **Python 3.6 with WebSockets module**. More in [Python WebSockets example](../../IqrfGatewayDaemon.md#python-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

No hardware wiring needed, both LED2 and LED3 are mounted on the board and connected to C1 and C2.

## Software

### A. Embedded JSON messages

We use standard DPA handler already loaded in board TR module.

#### API JSON message

We can manage diods via sending [Daemon JSON API](https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html) messages.

* LD2 (Green DIOD) ON/OFF
  * [Set LEDG request v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfEmbedLedg_Set-request-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfEmbedLedg_Set-request-1-0-0-example.json)
  * [Set LEDG response v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfEmbedLedr_Set-response-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfEmbedLedr_Set-response-1-0-0-example.json)

* LD3 (Red DIOD) ON/OFF
  * [Set LEDR request v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfEmbedLedr_Set-request-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfEmbedLedr_Set-request-1-0-0-example.json)
  * [Set LEDR response v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfEmbedLedr_Set-response-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfEmbedLedr_Set-response-1-0-0-example.json)

### Testing Software

The [embedded-led.py](https://github.com/logimic/iqrfboard/blob/master/examples/embedded-led.py) script also prints sent and received JSON messages.
