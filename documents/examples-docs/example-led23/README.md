# Set LED2, LED3 on/off

This example turns RED LED on, waits 2 seconds, then turns RED LED off and GREEN LED on, then after 2 seconds turns GREEN LED off.

## Links

* [IQRFBB-10 Datasheet](../../IQRFBB10-Datasheet.md)
* [IQRF Gateway Daemon Documentation](https://docs.iqrfsdk.org/iqrf-gateway-daemon/index.html)

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

The [example-led23.py](example-led23.py) script also prints sent and received JSON messages.
**Note:** Parameter **boardAddr** must be IQRFBB-10 node address in IQRF network.

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

# Websockets example-led23.py
import asyncio
import websockets
import json
import time

# This is IQRFBB-10 node address in IQRF network
boardAddr = 3

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"
LEDR_ON = {
  "mType": "iqrfEmbedLedr_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "onOff": True
      }
    },
    "returnVerbose": True
  }
}

LEDR_OFF = {
  "mType": "iqrfEmbedLedr_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "onOff": False
      }
    },
    "returnVerbose": True
  }
}

LEDG_ON = {
  "mType": "iqrfEmbedLedg_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "onOff": True
      }
    },
    "returnVerbose": True
  }
}

LEDG_OFF = {
  "mType": "iqrfEmbedLedg_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "onOff": False
      }
    },
    "returnVerbose": True
  }
}

async def hello():
    # Connect websockets
    async with websockets.connect(
            'ws://localhost:1338') as websocket:

        # RED LED ON
        await websocket.send(json.dumps(LEDR_ON))
        print(f"Sent > {LEDR_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")

        # Wait 2 sec
        time.sleep(2)

        # RED LED OFF
        await websocket.send(json.dumps(LEDR_OFF))
        print(f"Sent > {LEDR_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")        

        # GREEN LED ON
        await websocket.send(json.dumps(LEDG_ON))
        print(f"Sent > {LEDG_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")        

        # Wait 2 sec
        time.sleep(2)

        # GREEN LED OFF
        await websocket.send(json.dumps(LEDG_OFF))
        print(f"Sent > {LEDG_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")            

asyncio.get_event_loop().run_until_complete(hello())
```
