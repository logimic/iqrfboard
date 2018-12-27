# Hall Magnetic Sensor

![](example-hall.jpg)

This example shows how to connect [KS0020 Hall Magnetic Sensor](http://wiki.keyestudio.com/index.php/Ks0020_keyestudio_Hall_Magnetic_Sensor) with the board.

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [GettingStarted with IQRFBB-10](https://github.com/logimic/iqrfboard/wiki)
2. **IQRF Gateway Daemon** running. More in [IQRF Gateway Daemon](https://github.com/logimic/iqrfboard/wiki/IQRF-Gateway-Daemon)
3. **Python 3.6 with WebSockets module**. More in [Python 3.6 WbSockets example](https://github.com/logimic/iqrfboard/wiki/Get-IQRF-with-your-software#python-36-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

_Fig.: IQRFBB10 schema_

![](example-hall_bb.jpg)

_Fig.: External LED wiring_

Connect VO, EQ13 and GRND pins with [KS0020 Keyestudio Hall Magnetic Sensor](http://wiki.keyestudio.com/index.php/Ks0020_keyestudio_Hall_Magnetic_Sensor).

## Software

* We use Standard DPA handler already loaded in board TR module.
* Testing software:
  - Set EQ13 as DI. EQ13 is **Q13/RE3** pin on TR-76DA.
  - Read all DI in the loop
  - Parse response and make decision

### API JSON message

We will use pure DPA messages handled via [Daemon JSON API](https://docs.iqrfsdk.org/iqrf-gateway-daemon/):

* [RawHdp request  v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfRawHdp-request-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfRawHdp-request-1-0-0-example.json)
* [RawHdp response  v1-0-0](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/#iqrf/iqrfRawHdp-response-1-0-0.json), [..example](https://apidocs.iqrf.org/iqrf-gateway-daemon/json/iqrf/examples/iqrfRawHdp-response-1-0-0-example.json)

**DPA commands:**

| NADR | PNUM | PCMD | HWPID |  PDATA   | What                       |
|:----:|:----:|:----:|:-----:|:--------:| -------------------------- |
| XXXX |  09  |  00  | FFFF  | 10.08.08 | Set RE3 (Address E3) as DI |
| XXXX |  09  |  02  | FFFF  |          | Read all DI pins           |

* _NADR: must be your address of IQRFBB-10 in IQRF network._
* _Numbers in table are in hex format._

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

# Websockets example-hall.py
import asyncio
import websockets
import json
import time

# This is IQRFBB-10 node address in IQRF network
boardAddr = 3

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"
EQ13_IN = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 0,
      "pData": [16, 8, 8]
    },
    "returnVerbose": True
  }
}

READ_ALL = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 9,
      "pCmd": 2
    },
    "returnVerbose": True
  }
}

async def hello():
    # Connect websockets
    async with websockets.connect(
            'ws://localhost:1338') as websocket:            

        # Set EQ13 IN
        await websocket.send(json.dumps(EQ13_IN))
        print(f"Sent > {EQ13_IN}")

        response = await websocket.recv()
        print(f"Received < {response}")

        count = 0
        detected = False
        while (count < 20 and detected == False):
          print (f"The count is:{count}")
          count = count + 1
          # Read all pins
          await websocket.send(json.dumps(READ_ALL))
          print(f"Sent > {READ_ALL}")        

          response = await websocket.recv()
          print(f"Received < {response}")      

          # Parse JSON response
          data = json.loads(response)
          pData = data["data"]["rsp"]["pData"]
          button = pData[4]

          # Check input detection
          if button == 0:
            detected = True

        # Check input detection
        if detected == False:
          print(f"NOTHING detected :(")
        else:
          print(f"Input detected!!! :)")      

asyncio.get_event_loop().run_until_complete(hello())
```
