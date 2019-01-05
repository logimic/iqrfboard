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
BINOUT_ENUM = {
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

ALL_OFF = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 0,
            "state": False
          },
          {
            "index": 1,
            "state": False
          },
          {
            "index": 2,
            "state": False
          },
          {
            "index": 3,
            "state": False
          },
          {
            "index": 4,
            "state": False
          }                                        
        ]
      }
    },
    "returnVerbose": True
  }
}

LED3_ON = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 0,
            "state": True
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

LED3_OFF = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 0,
            "state": False
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

LED2_ON = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 1,
            "state": True
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

LED2_OFF = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 1,
            "state": False
          }
        ]
      }
    },
    "returnVerbose": True
  }
}

RELAY_ON = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 2,
            "state": True
          },
          {
            "index": 3,
            "state": False
          }          
        ]
      }
    },
    "returnVerbose": True
  }
}

RELAY_OFF = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 2,
            "state": False
          },
          {
            "index": 3,
            "state": True
          }          
        ]
      }
    },
    "returnVerbose": True
  }
}

LED_ON = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 4,
            "state": True
          }        
        ]
      }
    },
    "returnVerbose": True
  }
}

LED_OFF = {
  "mType": "iqrfBinaryoutput_SetOutput",
  "data": {
    "msgId": "testEmbedBout",
    "req": {
      "nAdr": boardAddr,
      "param": {
        "binouts": [
          {
            "index": 4,
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

        # List Lights...
        await websocket.send(json.dumps(BINOUT_ENUM))
        print(f"Sent > {BINOUT_ENUM}")

        response = await websocket.recv()
        print(f"Received < {response}")         

        data = json.loads(response)
        numOuts = data["data"]["rsp"]["result"]["binouts"]
        
        print("-------------------------------------")
        print(f"Node has implemented {numOuts} binary outputs!")
        print("-------------------------------------")
        print("wait...")

        # Wait 3 sec
        time.sleep(3)

        # Set all DO as LO
        await websocket.send(json.dumps(ALL_OFF))
        print(f"Sent > {ALL_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")        

        # Set LED2 as HI
        await websocket.send(json.dumps(LED2_ON))
        print(f"Sent > {LED2_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")

        print("\n---> LED2 is ON")

        # Wait 2 sec
        time.sleep(2)

        # Set LED2 as LO
        await websocket.send(json.dumps(LED2_OFF))
        print(f"Sent > {LED2_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")        
                
        # LED3 = HI
        await websocket.send(json.dumps(LED3_ON))
        print(f"Sent > {LED3_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")   

        print("\n---> LED3 is ON")        
        
        # Wait 2 sec
        time.sleep(2)             

        # LED3 = LO
        await websocket.send(json.dumps(LED3_OFF))
        print(f"Sent > {LED3_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")  

        await websocket.send(json.dumps(RELAY_OFF))
        print(f"Sent > {RELAY_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")      

        await websocket.send(json.dumps(RELAY_ON))
        print(f"Sent > {RELAY_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")     

        print("\n---> Now bi-stable relay")

        # Wait 2 sec
        time.sleep(2)      

        await websocket.send(json.dumps(RELAY_OFF))
        print(f"Sent > {RELAY_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")         
        
        # Wait 2 sec
        time.sleep(2)    

        await websocket.send(json.dumps(LED_ON))
        print(f"Sent > {LED_ON}")

        response = await websocket.recv()
        print(f"Received < {response}")    

        print("\n---> Now plays SCL/EQ13 out with external LED...")

        # Wait 2 sec
        time.sleep(5)    

        await websocket.send(json.dumps(LED_OFF))
        print(f"Sent > {LED_OFF}")

        response = await websocket.recv()
        print(f"Received < {response}")   

asyncio.get_event_loop().run_until_complete(hello())