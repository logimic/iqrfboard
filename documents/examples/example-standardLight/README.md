# Standard Light

This example shows how to create "Standard light" which means that entire world will know that your device is just a light and will be able to manage it (turn on/off, dim, get status and more). This is possible thanks to standardized API and IQRF gateways.

Standardization does not limit your hardware creativity, your light can be whatever you connect. The software in TR module makes connection with API. In following we will show how to implement two lights on the one board. The lights will be LED2 and LED3.

## Links

* [IQRFBB-10 Datasheet](../../IQRFBB10-Datasheet.md)
* [IQRF Gateway Daemon Documentation](https://docs.iqrfsdk.org/iqrf-gateway-daemon/index.html)
* [IQRF Standards](https://www.iqrfalliance.org/techDocs/)

## Prerequisities

1. **IQRFBB-10** bonded in working IQRF network. More in [Getting Started](../../README.md)
2. **IQRF Gateway Daemon** working. More in [IQRF Gateway Daemon](../../IqrfGatewayDaemon.md)
3. **Python 3.6 with WebSockets module**. More in [Python WebSockets example](../../IqrfGatewayDaemon.md#python-websocket-example)

## Hardware wiring

![](../../files/datasheet/layout.png)

No hardware wiring needed, lights will be demonstrated by LED2 and LED3.

## Software in TR module

The [example-standardLight.c](example-standardLight.c) implements two lights on LED2 and LED3 outputs.
Please load this "Custom DPA Handler" to TR module on board. [Load Custom DPA Handler](../../SetupIqrfNetwork.md#load-custom-dpa-handler) manual.


## API JSON message

Since we implemented standard light we can use standardized JSON messages for [management of Lights](https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html#light) via JSON API of gateways.

#### Python code

The [example-standardLight.py](example-standardLight.py) turns RED LED on, waits 2 seconds, then turns RED LED off and GREEN LED on, then after 2 seconds turns GREEN LED off.

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

# Websockets led-on-off.py
import asyncio
import websockets
import json
import time

# This is IQRFBB-10 node address in IQRF network
boardAddr = 3

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"
LIGHT_ENUM = {
  "mType": "iqrfLight_Enumerate",
  "data": {
    "msgId": "testEmbedLight",
    "req": {
      "nAdr": boardAddr,
      "param": {}
    },
    "returnVerbose": True
  }
}

LIGHT1_ON = {
  "mType": "iqrfLight_SetPower",
  "data": {
    "msgId": "testEmbedLight",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "lights": [
          {
            "index": 0,
            "power": 100
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

LIGHT1_OFF = {
  "mType": "iqrfLight_SetPower",
  "data": {
    "msgId": "testEmbedLight",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "lights": [
          {
            "index": 0,
            "power": 0
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

LIGHT2_ON = {
  "mType": "iqrfLight_SetPower",
  "data": {
    "msgId": "testEmbedLight",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "lights": [
          {
            "index": 1,
            "power": 100
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

LIGHT2_OFF = {
  "mType": "iqrfLight_SetPower",
  "data": {
    "msgId": "testEmbedLight",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "lights": [
          {
            "index": 1,
            "power": 0
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

async def hello():
    # Connect websockets
    async with websockets.connect(
            'ws://localhost:1338') as websocket:

        # List Lights...
        await websocket.send(json.dumps(LIGHT_ENUM))
        print(f"Sent > {LIGHT_ENUM}")

        response = await websocket.recv()
        print(f"Received < {response}")         

        data = json.loads(response)
        numLight = data["data"]["rsp"]["result"]["lights"]

        print("-------------------------------------")
        print(f"Node has implemented {numLight} ligts!")
        print("-------------------------------------")
        print("wait...")

        # Wait 3 sec
        time.sleep(3)

        # RED LED ON
        await websocket.send(json.dumps(LIGHT1_ON))
        print(f"Sent > {LIGHT1_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")

        # Wait 2 sec
        time.sleep(2)

        # RED LED OFF
        await websocket.send(json.dumps(LIGHT1_OFF))
        print(f"Sent > {LIGHT1_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")        

        # GREEN LED ON
        await websocket.send(json.dumps(LIGHT2_ON))
        print(f"Sent > {LIGHT2_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")        

        # Wait 2 sec
        time.sleep(2)

        # GREEN LED OFF
        await websocket.send(json.dumps(LIGHT2_OFF))
        print(f"Sent > {LIGHT2_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")            

asyncio.get_event_loop().run_until_complete(hello())
```
