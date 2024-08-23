Before proceeding to the LabVIEW deployment, make sure you have completed the steps described in LabVIEW_Library_QTM/README.md...

1. Open the LabVIEW Project LabVIEW_Library_QTM\Qualisys_RT\QualisysRT.lvproj
2. Add your cRIO to the project with the correct IP Address
3. Add LabVIEW_Library_QTM\Qualisys_RT\Qualisys_Dropped_Frames_Test.vi to your cRIO
4. Open the VI and make sure it finds all the source files (white run arrow means it's good)
5. Set the "ipAddress" control to the IP Address of the QTM server (check what you set the static IP of the Window's NIC to)
6. ssh into the cRIO again and make a directory for storing the data (i.e. /home/lvuser/Qualisys - this is where all the data will be stored)
7. Set "File save location" control in the VI to the folder you just created
8. Run the VI and see if you are seeing data come through
9. The TDMS files are written in 10 minute intervals - make sure these are looking good
10. Run wireshark on the Windows QTM machine to track all traffic on the QTM server nic (see below)
11. Run the test for a while and we can check to see if we're getting data drops
12. Send TDMS, log and wireshark data to team


Wireshark directions:
Step-by-Step Guide:

    Open Wireshark: Launch Wireshark on your computer.

    Select the NIC:
        In the main interface, you’ll see a list of available network interfaces.
        Look for the specific Ethernet NIC you want to capture traffic from. If you are unsure, you can identify it by its name or IP address.

    Start Capturing:
        Click on the interface associated with your Ethernet NIC.
        Alternatively, right-click the interface and choose Start Capture to begin capturing packets on that NIC.

    Capture All Traffic: Wireshark will capture all traffic passing through the selected NIC without filtering. If you want to capture only specific traffic types or protocols, you can use capture filters, but for capturing all traffic, no filter is necessary.

    Stop Capturing:
        Once you have captured enough data, click the red square button (Stop) in the Wireshark interface to halt the capture.

    Analyze the Captured Traffic:
        You can now inspect the captured traffic in the main window. Click on individual packets to see details like source, destination, protocols, and data.


    Save the Data