# IQRF Gateway Daemon
IQRF network is hidden behind coordinator connected to your computer via USB, SPI, UART or other types of interface. Communication between your program and coordinator is ensured via **IQRF Gateway Daemon** software module.
This is Open Source gateway piece of software for communicating (sending and receiving JSON API messages) with IQRF network. This is included in many IQRF gateways and you can also download it and build for your platform. In releases of this repo we prepared build for Win developers.

* Download sources: https://gitlab.iqrfsdk.org/gateway/iqrf-daemon
* Download releases: https://github.com/logimic/iqrfboard/releases
* Documentation: https://docs.iqrfsdk.org/iqrf-gateway-daemon/

Demon provides many software interface channels:

* WebSockets
* MQTT
* MQ interprocess

Every channel can be used for sending/receiving JSON API messages. Full API is described here: https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html

## Run Daemon
Please follow instructions at releases: https://github.com/logimic/iqrfboard/releases

## WebSockets JSON API
WebSockets port is opened during start o Daemon. The number of port is defined in **IqrfDaemon\runcfg\iqrfgd2-WinCdc\configuration\iqrf__WebsocketMessaging.json**.  You can change it, but please do not forget to restart Daemon then.

### Html WebSocket example
* Open html page **https://github.com/logimic/iqrfboard/blob/master/tools/index-1338.html**
* Enter message:
```json
{
  "mType": "iqrfEmbedLedg_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": 0,
      "param": {
        "onOff": true
      }
    },
    "returnVerbose": true
  }
}
```
* Press **Send** in html page and see that this turned on the LED diod on concentrator module.
* Similar way you can turn LED off:
 ```json
{
  "mType": "iqrfEmbedLedg_Set",
  "data": {
    "msgId": "testEmbedLedr",
    "req": {
      "nAdr": 0,
      "param": {
        "onOff": false
      }
    },
    "returnVerbose": true
  }
}
```
* Similarly for other nodes by changing **nAdr** parameter indicating the node address.
* Full API description can be found here: https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html

### Python 3.6 WebSocket example
* Install ```pip install websockets```
* Write simple program **[GreenLedOn.py](tools/GreenLedOn.py)**
```py
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
```
* Run it ``$ py ./GreenLedOn.py`` and the green LED on coordinator turns on.
* Changing **nAdr** will address command to other node, the **"onOff": False** will turn LED off.
* Full API description can be found here: https://docs.iqrfsdk.org/iqrf-gateway-daemon/api.html
