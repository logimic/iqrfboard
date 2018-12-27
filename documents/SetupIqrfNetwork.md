# Setup IQRF Network

![](https://iqrf.org/images/ds-start-04-case.jpg)

Start building your IQRF network with **DS-START-04** development kit.

## Links
* [Order here](https://iqrf.org/products/ds-start-04)
* [The Content of the Starter Kit](files/iqrf/README_150909.pdf)
* [IQRF Quick Start Guide](https://github.com/logimic/iqrfboard/blob/master/files/iqrf/Quick_Start_Guide_IQRF_181018.pdf)
* [CK-USB-04A](https://github.com/logimic/iqrfboard/blob/master/files/iqrf/User_Guide_CK-USB-04A_171109.pdf), [online page...](https://iqrf.org/products/development-tools/development-kits/ck-usb-04a)
* [...check for updates ](https://iqrf.org/products/ds-start-04)

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
