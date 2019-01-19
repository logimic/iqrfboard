# Bi-stable relay

This example turns bistable relay on/off.

## Links

* [IQRFBB-10 Datasheet](../../IQRFBB10-Datasheet.md)

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

The [example-bistable-relay.py](example-bistable-relay.py) script.

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

# Websockets example-bistable-relay.py
import asyncio
import websockets
import json
import time

# This is IQRFBB-10 node address in IQRF network
boardAddr = 3

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"
C1_OUT = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 0,
      "pData": [0, 1, 0]
    },
    "returnVerbose": True
  }
}

C1_ON = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 1,
      "pData": [0, 1, 1]
    },
    "returnVerbose": True
  }
}

C1_OFF = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 1,
      "pData": [0, 1, 0]
    },
    "returnVerbose": True
  }
}

C2_OUT = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 0,
      "pData": [2, 4, 0]
    },
    "returnVerbose": True
  }
}

C2_ON = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 1,
      "pData": [2, 4, 4]
    },
    "returnVerbose": True
  }
}

C2_OFF = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 1,
      "pData": [2, 4, 0]
    },
    "returnVerbose": True
  }
}

async def hello():
    # Connect websockets
    async with websockets.connect(
            'ws://localhost:1338') as websocket:            

        # Set C1 OUT
        await websocket.send(json.dumps(C1_OUT))
        print(f"Sent > {C1_OUT}")

        response = await websocket.recv()
        print(f"Received < {response}")

        # Set C2 OUT
        await websocket.send(json.dumps(C2_OUT))
        print(f"Sent > {C2_OUT}")        

        response = await websocket.recv()
        print(f"Received < {response}")     

        # Set C2 OFF
        await websocket.send(json.dumps(C2_OFF))
        print(f"Sent > {C2_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")           

       # Set C1 ON
        await websocket.send(json.dumps(C1_ON))
        print(f"Sent > {C1_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")

        print("Waiting 3 secs then reswitch...")
        # Wait 3 sec
        time.sleep(3)       

        # Set C1 OFF
        await websocket.send(json.dumps(C1_OFF))
        print(f"Sent > {C1_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")        

        # Set C2 ON
        await websocket.send(json.dumps(C2_ON))
        print(f"Sent > {C1_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")                     


asyncio.get_event_loop().run_until_complete(hello())
```
