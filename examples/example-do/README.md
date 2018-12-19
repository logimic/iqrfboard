# Digital Output

This example shows how to set DO on board. We will power EQ6 (X10 SCL) pin.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [GettingStarted with IQRFBB-10](https://github.com/logimic/iqrfboard/wiki)
2. **IQRF Gateway Daemon** running. More in [IQRF Gateway Daemon](https://github.com/logimic/iqrfboard/wiki/Get-IQRF-with-your-software#iqrf-gateway-daemon)
3. **Python 3.6 with WebSockets module**. More in [Python 3.6 WbSockets example](https://github.com/logimic/iqrfboard/wiki/Get-IQRF-with-your-software#python-36-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

_Fig.: IQRFBB10 schema_

![](example-do_bb.png)

_Fig.: External LED wiring_

Connect EQ13 and GRN pins via button.

## Software

* We use Standard DPA handler already loaded in board TR module.
* Testing software:
  - Set EQ6 (X10 SCL) as DO. EQ16 is **Q6, C6/RC3** genral I/O pin on TR-76DA.
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

_NADR: must be your address of IQRFBB-10 in IQRF network._

### Testing Software

The [example-di.py](example-di.py) code:

```py
#
# Copyright 2018 Logimic,s.r.o.
# www.logimic.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Websockets example-do.py
import asyncio
import websockets
import json
import time

# This is IQRFBB-10 node address in IQRF network
boardAddr = 3

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"
RC3_OUT = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 0,
      "pData": [2, 8, 0]
    },
    "returnVerbose": True
  }
}

RC3_ON = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 1,
      "pData": [2, 8, 8]
    },
    "returnVerbose": True
  }
}

RC3_OFF = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 1,
      "pData": [2, 8, 0]
    },
    "returnVerbose": True
  }
}


async def hello():
    # Connect websockets
    async with websockets.connect(
            'ws://localhost:1338') as websocket:            

        # Set RC3 OUT
        await websocket.send(json.dumps(RC3_OUT))
        print(f"Sent > {RC3_OUT}")

        response = await websocket.recv()
        print(f"Received < {response}")

        # Set RC3 ON
        await websocket.send(json.dumps(RC3_ON))
        print(f"Sent > {RC3_ON}")        

        response = await websocket.recv()
        print(f"Received < {response}")         

        print("RC3 power ON...")

        # Wait 2 sec
        time.sleep(3)          

        # Read all pins
        await websocket.send(json.dumps(RC3_OFF))
        print(f"Sent > {RC3_OFF}")        

        response = await websocket.recv()
        print(f"Received < {response}")       

asyncio.get_event_loop().run_until_complete(hello())
```
