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