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