# Bi-stable relay

This example turns bistable relay on/off.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [GettingStarted with IQRFBB-10](https://github.com/logimic/iqrfboard/wiki)
2. **IQRF Gateway Daemon** running. More in [IQRF Gateway Daemon](https://github.com/logimic/iqrfboard/wiki/IQRF-Gateway-Daemon)
3. **Python 3.6 with WebSockets module**. More in [Python 3.6 WbSockets example](https://github.com/logimic/iqrfboard/wiki/Get-IQRF-with-your-software#python-36-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

No hardware wiring needed, bistable relay is managed via C1 and C2 signals. See. [Documentation](https://github.com/logimic/iqrfboard/wiki/Getting-Started-with-IQRFBB-10#iqrfbb-10-documentation)

## Software

* We use Standard DPA handler already loaded in board TR module.
* Testing software:
  - Set EQ14 as DO. EQ14 is **Q14/C1/RA0** pin on TR-76DA.
  - Set EQ15 as DO. EQ15 is **Q15/C2/RC2** pin on TR-76DA.
  - Set C2=LO, C1=HI
  - Wait 3secs
  - Set C2=HI, C1=LO

### API JSON message

We will use pure DPA messages handled via [Daemon JSON API](https://docs.iqrfsdk.org/iqrf-gateway-daemon/):

* [RawHdp request  v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfRawHdp-request-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfRawHdp-request-1-0-0-example.json)
* [RawHdp response  v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfRawHdp-response-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfRawHdp-response-1-0-0-example.json)

**DPA commands:**

| NADR | PNUM | PCMD | HWPID |  PDATA   | What          |
|:----:|:----:|:----:|:-----:|:--------:| ------------- |
| XXXX |  09  |  00  |   -   | 00.01.00 | Set C1 Output |
| XXXX |  09  |  00  |   -   | 02.04.00 | Set C2 Output |
| XXXX |  09  |  01  |   -   | 00.01.01 | Set C1 ON     |
| XXXX |  09  |  01  |   -   | 00.01.00 | Set C1 OFF    |
| XXXX |  09  |  01  |   -   | 02.04.04 | Set C2 ON     |
| XXXX |  09  |  01  |   -   | 02.04.00 | Set C2 OFF    |

* _NADR: must be your address of IQRFBB-10 in IQRF network._
* _Numbers in table are in hex format._

### Testing Software

The [dpa-bistable-relay.py](https://github.com/logimic/iqrfboard/blob/master/examples/dpa-bistable-relay.py) script.
