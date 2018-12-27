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

        # Wait 3 sec
        time.sleep(3)          

        # Read all pins
        await websocket.send(json.dumps(RC3_OFF))
        print(f"Sent > {RC3_OFF}")        

        response = await websocket.recv()
        print(f"Received < {response}")       

asyncio.get_event_loop().run_until_complete(hello())