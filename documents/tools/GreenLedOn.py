# WS client example
import asyncio
import websockets
import json

x = {
  "mType": "iqrfEmbedLedg_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": 0,
      "param": {
        "onOff": True
      }
    },
    "returnVerbose": False
  }
}

async def hello():
    async with websockets.connect(
            'ws://localhost:1338') as websocket:

        await websocket.send(json.dumps(x))
        print(f"Sent > {x}")

        greeting = await websocket.recv()
        print(f"Received < {greeting}")

asyncio.get_event_loop().run_until_complete(hello())