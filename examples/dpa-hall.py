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