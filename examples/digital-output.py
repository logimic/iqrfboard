# 
# Copyright Logimic,s.r.o., www.logimic.com
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

import asyncio
import websockets
import json
import time

# This is IQRFBB-10 node address in IQRF network
boardAddr = 3

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"


BIN_OUT = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binOuts": [
          {
            "index": 0,
            "state": False
          },
          {
            "index": 1,
            "state": False
          }
        ]
      },
      "hwpId": 0
    },
    "returnVerbose": True
  }
}

BIN_ENUM = {
  "mType": "iqrfBinaryoutput_Enumerate",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {}
    },
    "returnVerbose": True
  }
}

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

LIGHT_ON = {
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

async def hello():
    # Connect websockets
    async with websockets.connect(
            'ws://localhost:1338') as websocket:            

        await websocket.send(json.dumps(LIGHT_ENUM))
        print(f"Sent > {LIGHT_ENUM}")

        response = await websocket.recv()
        print(f"Received < {response}")                    

        time.sleep(2) 

        await websocket.send(json.dumps(BIN_ENUM))
        print(f"Sent > {BIN_ENUM}")

        response = await websocket.recv()
        print(f"Received < {response}")                    

        time.sleep(2)         

        # Set RC3 OUT
        await websocket.send(json.dumps(BIN_OUT))
        print(f"Sent > {BIN_OUT}")

        response = await websocket.recv()
        print(f"Received < {response}")

        await websocket.send(json.dumps(LIGHT_ON))
        print(f"Sent > {LIGHT_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")        
        
        
        print("BIN_OUT done...")

        # Wait 3 sec
        time.sleep(3)          

  

asyncio.get_event_loop().run_until_complete(hello())