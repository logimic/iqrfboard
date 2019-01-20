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
boardAddr = 1

# JSON messages by "https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html"
GET_PERIPHERIAL = {
  "mType": "iqrfRawHdp",
  "data": {
    "msgId": "testRawHdp",
    "req": {
      "nAdr": boardAddr,
      "pNum": 0x20,
      "pCmd": 0
    },
    "returnVerbose": True
  }
}

async def hello():
    # Connect websockets
    async with websockets.connect('ws://localhost:1338') as websocket:            

        count = 0
        while (count < 50):
          print(f"The count is:{count}")
          count = count + 1
          # Read all pins
          await websocket.send(json.dumps(GET_PERIPHERIAL))
          #print(f"Sent > {GET_PERIPHERIAL}")

          response = await websocket.recv()
          #print(f"Received < {response}")

          data = json.loads(response)
          tempH = data["data"]["rsp"]["pData"][0]
          tempL = data["data"]["rsp"]["pData"][1]
          temp = (tempH << 8 | tempL) & 0xFFFC
          dtemp = temp / 65536.0
          dtepm = -46.85 + (175.72 * dtemp)
          humH = data["data"]["rsp"]["pData"][3]
          humL = data["data"]["rsp"]["pData"][4]
          hum = (tempH << 8 | tempL) & 0xFFFC
          dhum = hum / 65536.0
          dhum = -6.0 + (125.0 * dhum)
          print(f"Temperature = {dtepm:3.3f} Humidity = {dhum:3.3f}")
          

        print("DONE....")
          
asyncio.get_event_loop().run_until_complete(hello())