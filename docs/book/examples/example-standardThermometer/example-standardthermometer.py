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
SENSORS_ENUM = {
  "mType": "iqrfSensor_Enumerate",
  "data": {
    "msgId": "testEmbedSensor",
    "req": {
      "nAdr": boardAddr,
      "param": {}
    },
    "returnVerbose": True
  }
}

READ_TEMP = {
  "mType": "iqrfSensor_ReadSensorsWithTypes",
  "data": {
    "msgId": "testEmbedSensor",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "sensorIndexes": [
          0
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
        await websocket.send(json.dumps(SENSORS_ENUM))
        print(f"Sent > {SENSORS_ENUM}")

        response = await websocket.recv()
        print(f"Received < {response}")         

        data = json.loads(response)
        numOuts = data["data"]["rsp"]["result"]["sensors"]
        
        print("-------------------------------------")
        print(f"Node has implemented {len(numOuts)} sensors!")
        print("-------------------------------------")
        print("wait...")

        # Wait 2 sec
        time.sleep(2)

        count = 0        
        while (count < 200):
          print (f"The count is:{count}")
          count = count + 1

          await websocket.send(json.dumps(READ_TEMP))
          print(f"Sent > {READ_TEMP}")

          response = await websocket.recv()
          print(f"Received < {response}")           

          data = json.loads(response)
          value = data["data"]["rsp"]["result"]["sensors"][0]["value"]

          print(f"\n\n---> Measured: {value} \n")

        print("\n---> End of measurement...")


asyncio.get_event_loop().run_until_complete(hello())