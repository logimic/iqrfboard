# Digital Output

![](digital-output.jpg)

This example shows how to set EQ6 (X10 SCL) pin of the board.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [Getting Started](../../README.md)
2. **IQRF Gateway Daemon** working. More in [IQRF Gateway Daemon](../../IqrfGatewayDaemon.md)
3. **Python 3.6 with WebSockets module**. More in [Python WebSockets example](../../IqrfGatewayDaemon.md#python-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

_Fig.: IQRFBB10 schema_

![](digital-output_bb.png)

_Fig.: External LED wiring_

Connect SCL and GRN pins via button.

## Software

* We use Standard DPA handler already loaded in board TR module.
* Testing software:
  - Set EQ6 (X10 SCL) as DO. EQ6 is **Q6, C6/RC3** genral I/O pin on TR-76DA.
  - Set pin HI
  - Wait 3sec
  - Set pin LO

### API JSON message

We will use DPA messages handled via [Daemon JSON API](https://docs.iqrfsdk.org/iqrf-gateway-daemon/):

* [RawHdp request  v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfRawHdp-request-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfRawHdp-request-1-0-0-example.json)
* [RawHdp response  v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfRawHdp-response-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfRawHdp-response-1-0-0-example.json)

**DPA commands:**

| NADR | PNUM | PCMD | HWPID |  PDATA   | What                       |
|:----:|:----:|:----:|:-----:|:--------:| -------------------------- |
| XXXX |  09  |  00  | FFFF  | 02.08.00 | Set RC3 (Address C3) as D0 |
| XXXX |  09  |  01  | FFFF  | 02.08.08 | Set pin HI                 |
| XXXX |  09  |  01  | FFFF  | 02.08.00 | Set pin LO                 |

* _NADR: must be your address of IQRFBB-10 in IQRF network._
* _Numbers in table are in hex format._

### Testing Software

The [digital-output.py](https://github.com/logimic/iqrfboard/blob/master/examples/digital-output.py).
