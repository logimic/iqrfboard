# Setup IQRF Network

![](https://iqrf.org/images/ds-start-04-case.jpg)

You can get many pieces of information about IQRF at [iqrf.org](http://iqrf.org) page. Simply said IQRF network is mesh kind of network working very well indoor and outdoor (up to 500m). It has one device as **concentrator** connected to gateway or your PC and the rest of devices are **wireless nodes**.

The best start with IQRF is with their **DS-START-04** development kit. It helps you to create your first IQRF network for testing purposes. In this tutorial we will show you how to create IQRF network with this kit.

## Install IDE

![aaa](files/images/SetupIqrfNetwork/iqrf-ide-4.jpg)

IDE is a basic programming tool for IQRF devices. Download and install [https://www.iqrf.org/technology/iqrf-ide/iqrf-ide-gui](https://www.iqrf.org/technology/iqrf-ide/iqrf-ide-gui)

## Install IQRF Startup Package

Download [IQRF Startup package](https://www.iqrf.org/support/download&kat=34&ids=82) and unpack anywhere to your hard drive.

## First Start

* Start your IDE, navigate to your installed **IQRF Startup package** e.g. _d:\IQRF_OS403_7xD\Examples\DPA\StartUp_ and open **HWP-demo.iqrfprj**

* Insert any IQRF module to programmer [CK-USB-04A](https://iqrf.org/products/development-tools/development-kits/ck-usb-04a) and connect to PC via USB.

![image](files/images/SetupIqrfNetwork/50103857-e4acfb80-0228-11e9-88f1-a1ad28f00ad7.png)

* In IDE you will probably see **USB device not connected** in bottom panel.

![image](files/images/SetupIqrfNetwork/50103939-1c1ba800-0229-11e9-94af-0bcc89113d04.png)

* Go to menu **Tools/USB Classes/Swith to Custom Device mode** and select listed COM (USB) port. If you do not see any port please follow troubleshooting on IQRF support. You need driver update. Successful selection will show dialogue like this.

![image](files/images/SetupIqrfNetwork/50104128-951aff80-0229-11e9-847e-c5b43c73facd.png)

* Click **Switch** and the bottom panel will show **Module ready - communication mode**

![image](files/images/SetupIqrfNetwork/50104213-c693cb00-0229-11e9-8b1a-eaa285ab2e12.png)

* It might show dialogue about firmware update, then click **Yes**.

![image](files/images/SetupIqrfNetwork/50104292-e925e400-0229-11e9-944c-48f94d5933d0.png)

* Click **Upload** button, wait for firmware update, then press **Close**.

![image](files/images/SetupIqrfNetwork/50104371-20949080-022a-11e9-9835-adef5a4ccb4f.png)

## Configure Coordinator

A Concentrator is the node connected with PC or Gateway gathering data from all nodes.
**! When you insert or remove TR from holder, always press SW2 button (nearer to SIM slot). It breaks power.**

* In left panel check **HWP-Coordinator-...iqrf** file

![image](files/images/SetupIqrfNetwork/50106144-38bade80-022f-11e9-84f2-e2ac42f16666.png)

* Double click on **DPA-config.xml** in left panel. Set items in dialogue as picture shows and click **Upload** button.

![image](files/images/SetupIqrfNetwork/50106039-d661de00-022e-11e9-8fc5-74a5a7c65aad.png)

![image](files/images/SetupIqrfNetwork/50106117-1b861000-022f-11e9-95ed-6d19edda9113.png)

* In menu select **Programming/Upload/Upload Selected Items**. If the system complains that uploading version is not for the connected TR module, please upgrade OS in module. See **Upgrade OS in TR module** section.

## Configure Nodes

A Node is a module communication within mesh with Concentrator.
**! When you insert or remove TR from holder, always press SW2 button (nearer to SIM slot). It breaks power.**

* Insert TR module to be node into programmer

* In left panel of IDE check **HWP-Node-STD-...**

![image](files/images/SetupIqrfNetwork/50108583-e630f080-0235-11e9-9843-d5ec00d6e3de.png)

* Keep the **DPA-config.xml** settings as previously at concentrator.

* Upload all your nodes. If the system complains that uploading version is not for the connected TR module, please upgrade OS in module. See **Upgrade OS in TR module** section.

## Upgrade OS in modules

* In menu select **Tools/Change IQRF OS Wizard** and follow wizard.

* Use **SPI** as upload method.

![image](files/images/SetupIqrfNetwork/50106475-3311c880-0230-11e9-80ea-061aae079706.png)

* Then select version to be uploaded

![image](files/images/SetupIqrfNetwork/50106345-e62df200-022f-11e9-9212-d1594fe6a943.png)

* **!If your modules are older you might need to repeat the upgrade OS more times**

## Run Network

* Insert coordinator configured TR module to programmer CK-USB-04A and nodes to other DK-EVAL-04A modules.

* In IDE in menu start **Tools/IQMESH Network Manager** and fill out the dialogue as shown (TX power, Auto address, ...).

![image](files/images/SetupIqrfNetwork/50110959-dfa57780-023b-11e9-981a-a1f883e7cac8.png)

* Then pres **Clear All Bonds** for remove any previous bonded modules. Red diods of modules are blinking.

* Then pres **Bond Node** and during bonding period press and hold SW1 button at one node until green red turns on. Repeat for each node.

![image](files/images/SetupIqrfNetwork/50111045-1aa7ab00-023c-11e9-9cf2-87ef0281bfc2.png)

* Now you should see two spots indicating successful bonding. Now click **Discovery** and spots are in blue.

![image](files/images/SetupIqrfNetwork/50111460-1e87fd00-023d-11e9-84e3-dad67435fbf2.png)

* Switch in IDE to **Map View** and you should see node structure

![image](files/images/SetupIqrfNetwork/50111497-31023680-023d-11e9-85c5-4a8288baeb72.png)

* Click right mouse button on node 1 and select **LED Red On**

![image](files/images/SetupIqrfNetwork/50111606-6b6bd380-023d-11e9-9030-746fe0c9a3f9.png)

* Now you can see that the **RED LED** of node 1 is on. In similar way you can turn-off or play with LEDs.

## Send DPA messages

Direct Peripheral Access (DPA) protocol is a simple byte-oriented protocol used to control nodes and network. Detail description of [DPA Framework](https://www.iqrf.org/DpaTechGuide/)

* DPA can be sent via IDE. Open **Terminal** and click **Set LEDR on** which prefills data into **Data to send** fields. Change only **NADR=0001** which indicates node 1 and click **Send**.

![image](files/images/SetupIqrfNetwork/50230461-00d9a580-03ad-11e9-9842-85226f02f424.png)

* This DPA command turned on RED diod on node 1.
* You can define any other DPA messages.

## Load Custom DPA Handler

**Custom DPA Handler** is software routine which is executed within transceiver MCU and where you can put your customer code to modify.

In **IDE Project** window you can see actually loaded **CustomDpaHandler** under **Source** item. Under **Output HEX** is its compiled code.
You can click right mouse button above source of **CustomDpaHandler-..** file and choose **Build** from menu for rebuilding of handler.

![image](files/images/SetupIqrfNetwork/CustomDpaHandler.png)

You can load any other Custom DPA Handler from prepared set in IQRF SDK here: **./IQRF_OS403_7xD/Examples/DPA/CustomDpaHandlerExamples** or you can modify any or write your own. **Note:** When you create your own handler, put it into **CustomDpaHandlerExamples** folder to be available others IQRF header files.

**Adding of your Custom DPA Handler:**

1. Right-click on any existing Custom DPA Handler under **Source**.
2. From context menu select **Add/Add Existing Item** and select your **CustomDpaHandler.c** file.
3. Make sure your handler is selected and via right-click select **Build** for its rebuild.
4. You will see its compiled **.hex** state under **Output Hex** item.
![image](files/images/SetupIqrfNetwork/CustomDpaHandler2.png)
5. Right-click on the **.hex** file and select **Upload**. Now the handler will be uploaded to TR module.
![image](files/images/SetupIqrfNetwork/CustomDpaHandler3.png)
6. Then double-click on **DPA-config.xml** and in dialogue tick **Custom DPA Handler** and then **Upload**.
![image](files/images/SetupIqrfNetwork/CustomDpaHandler4.png)

## Your own IQRF devices

Now it's time to build your own IQRF device. The best start is with IQRFBB-10 development board from [Logimic](http://www.logimic.com) because it has many examples and you can reuse board layout and design for your later product development. Let's go with [IQRFBB-10 board](README.md)

## Links
[Links](Links.md)
