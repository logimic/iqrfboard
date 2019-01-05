# IQRF Gateway Daemon
IQRF network is hidden behind coordinator connected to your computer via USB, SPI, UART or other types of interface. Communication between your program and coordinator is ensured via **IQRF Gateway Daemon** software module.
This is Open Source gateway piece of software for communicating (sending and receiving JSON API messages) with IQRF network. This is included in many IQRF gateways and you can also download it and build for your platform.

## Links

* [IQRF Gateway Daemon Sources](https://gitlab.iqrfsdk.org/gateway/iqrf-daemon)
* [IQRF Gateway Daemon Release for Win](https://github.com/logimic/iqrfboard/releases)
* [IQRF Gateway Daemon Documentation](https://docs.iqrfsdk.org/iqrf-gateway-daemon/)

## Run Daemon
You can run Daemon on any computer with Lin or Win platform where you have connected concentrator via USB or otherwise. The most simply way is to connect concentrator via USB to your local PC and run Daemon here.

### Windows Developers
 We prepared [IQRF Gateway Daemon Release for Win](https://github.com/logimic/iqrfboard/releases), please follow instruction how to install and start.

### Linux Developers
Please install from packages as described in [IQRF Gateway Daemon Documentation](https://docs.iqrfsdk.org/iqrf-gateway-daemon/). After restart of your Linux machine Dameon will really run as "Daemon".

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

### Python WebSocket example
* Install Python 3.6
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
