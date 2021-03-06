# Getting Started with IQRFBB-10
![](files/images/iqrfboardSystem.png)

IQRFBB-10 development board helps you to design IOT devices for IQRF wireless network. Simply connect sensor or actuator you want to, join the board to IQRF network and device is ready.
If you are satisfied with such working device scale IQRFBB-10 layout to final product and your IOT product is done.

In this tutorial we will show you:

* How to prepare IQRF network.
* How to connect IQRFBB-10 to the IQRF network as a node.
* How to connect different sensors to the board.
* How to communicate with the board from your software via IQRF gateway.

## Prepare IQRF network
Firs check IQRF network around you. If you do not have any, let's start with this tutorial [SetupIqrfNetwork](SetupIqrfNetwork.md).

## Assemble Board
![](files/datasheet/layout.png)

![](files/images/assemble1.png)

![](files/images/assemble2.png)

* JP1: OFF
* JP6: OFF
* Insert IQRF TR into board

## Connect Programmer
![](files/images/connectProgrammer.png)

1. Unplug USB cable from CK-USB-04A

2. Unplug IQRFBB-10 from microUSB and JP6=OFF.

3. Unplug TR module JP1=OFF.

4. Make wiring

5. Plug JP4=ON, JP1=OFF.

6. Plug micro-USB to IQRFBB-10 to power-on. Indication LD1=ON (charging battery), LD4=ON

7. Plug micro-USB to CK-USB-04A

8. Now the board is ready for software loading

## Load Software
If we are talking about software loading, we always mean loading software to IQRF transceiver TR-76D mounted on IQRFBB-10. Via software load you configure transceiver within IQRF network. Now we will configure board (transceiver) as a node of IQRF network.

1. Make sure you made a proper wiring and both USB power sources (programmer + board) are on.

2. Now you can upload node configuration as described in [preparation of your IQRF network chapter](SetupIqrfNetwork.md#configure-nodes). **Do not put any IQRF module into CK-USB-04A programmer SIM!**

3. Uploading data into transciever is sihnalized by LD3 diod on IQRFBB-10 board.

4. Unplug micro USB of CK-USB-04A programmer

5. Unplug micro USB of IQRFBB-10 board.

6. Unplug CK-USB-04A from IQRFBB-10.

## Bond to Network
Bonding IQRF nodes is generally [described here...](SetupIqrfNetwork.md#run-network), bonding IQRFBB-10 board goes this way:

1. Turn on battery power **JP6 = ON**. Diod indicating power on is **LD4 = ON**.

2. Turn TR module power **JP1 = ON**.

3. Open IDE, then menu start Tools/IQMESH Network Manager and fill out the dialogue as shown (TX power, Auto address, ...).
![image](files/images/SetupIqrfNetwork/50110959-dfa57780-023b-11e9-981a-a1f883e7cac8.png)

4. Then pres **Clear All Bonds** for remove any previous bonded modules. Red diods of modules are blinking, at IQRFBB-10 it is diod **LD3**.

5. Then pres **Bond Node** and during bonding period press and hold SW1 button at one node until green diod turns on. Repeat for each node. At IQRFBB-10 the SW1 is an external contact **EQ12, GND**, red diod is **LD3** and green diods is **LD2**.
![image](files/images/SetupIqrfNetwork/50111045-1aa7ab00-023c-11e9-9cf2-87ef0281bfc2.png)

6. Now you should see yellow spots indicating successful bonding. Now click **Discovery** and spots are in blue.
![image](files/images/SetupIqrfNetwork/50111460-1e87fd00-023d-11e9-84e3-dad67435fbf2.png)

7. Switch in IDE to **Map View** and you should see node structure something like in the picture.
![image](files/images/SetupIqrfNetwork/50150685-ff31b400-02be-11e9-87ce-2cb083b50bf1.png)

8. Try to turn on **LD3 (RED diod)** on IQRFBB-10 board. Click rigt mouse button on spot indicating board (it depends on the bonding order) and select **LED Red On**. Then the **LD3 = ON** on the board.
![image](files/images/SetupIqrfNetwork/50150771-3a33e780-02bf-11e9-89e6-dce0b8d8afeb.png)

## Check Operability
Now you have fully configured IQRFBB-10 board. You can check operability this way:

1. Battery power turn on/off is always done via **JP6**. When you power board on, then it is always automatically connected to the IQRF network (if you properly did all steps above).

2. For checking of connectivity open **IDE** and in **IQMESH Network Manager**, view **Control** click **Discovery** button. Working nodes are displayed in blue spots, previously bonded but inactive are shown as yellow spots.
![image](files/images/SetupIqrfNetwork/50151376-078aee80-02c1-11e9-9924-8bd87201d565.png)

3. Switch to **Map View**, find IQRF-BB10 node (one of blue spheres) and try to turn on **LD3 (RED diod)** on IQRFBB-10 board. Right click mouse button on spot indicating board and select **LED Red On**. Then the **LD3 = ON** on the board.
![image](files/images/SetupIqrfNetwork/50150771-3a33e780-02bf-11e9-89e6-dce0b8d8afeb.png)

## Examples
Now we can make from IQRFBB-10 any wireless sensor or actuator by wiring proper sensor or actuators. Let's continue to [our examples](Examples.md)

## Links
[Links](Links.md)
