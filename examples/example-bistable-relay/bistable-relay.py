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
BI_ON = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binOuts": [
          {
            "index": 1,
            "state": True
          },
          {
            "index": 2,
            "state": False
          }          
        ]
      }
    },
    "returnVerbose": True
  }
}

BI_OFF = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binOuts": [
          {
            "index": 1,
            "state": False
          },
          {
            "index": 2,
            "state": False
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

        # RED LED ON
        await websocket.send(json.dumps(BI_ON))
        print(f"Sent > {BI_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")

        # Wait 2 sec
        time.sleep(2)  

        # RED LED ON
        await websocket.send(json.dumps(BI_OFF))
        print(f"Sent > {BI_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")
        

asyncio.get_event_loop().run_until_complete(hello())