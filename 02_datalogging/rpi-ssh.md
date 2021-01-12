# Connect to your Pi via SSH

## Activate SSH

### Without a monitor and keyboard

1. Make sure Raspbian is properly installed on your SD card
2. Read the SD card content with your laptop and navigate to the boot folder (this is the root folder of your SD card).
3. Create a new empty file and name it `ssh` (without an extension) - in terminal this is with `touch ssh`
4. If you want to configure WiFi already, create a file in the root of boot called `wpa_supplicant.conf`, then past the following into it:
```
country=US
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
    ssid="NETWORK-NAME"
    psk="NETWORK-PASSWORD"
}
```
5. Safely remove your SD card from your laptop and insert it again in your Pi
6. Boot up your Pi, you should have SSH enabled. 

### With a monitor and keyboard

#### GUI

1. Boot up your Pi
2. Preferences >  Raspberry Pi Configuration > Interfaces > Enable SSH

#### Terminal

1. Boot up your Pi and open the terminal
2. Type `sudo raspi-config`
3. Navigate to `Interfacing options` > `ssh` > yes

## Know your IP address

Firstly, you need to connect to a network. You can connect to WiFi via `sudo raspi-config` or by Step 5 in the SD card setup from above. If you have an ethernet connection, you can avoid this step and just plug it into the pi's connector. Open the terminal and type `hostname -l` or `ip addr` for all the network interfaces. You should see your IP address there.

## Set a new password

On Raspbian, default username is `pi` and password is `raspberry`. You may want to set a new and personal password for security reasons. To do so:

1. Open the terminal and type `passwd`
2. Follow the instructions

## Access your Pi via SSH

1. Open the terminal
2. Type: `ssh pi@[raspberrypi_ip_address]`
3. Type your password
4. You are in!

## Copy files from your computer to the Pi via SSH

1. Open the terminal
2. Locate the file you want to copy
3. Locate where you want to put it in the raspberry pi, (`/home/pi` is a good place)
4. Copy it, in this case, we are copying a file called, `test.py` from the Desktop on the origin laptop to the `/home/pi` folder in the raspberry pi: `scp /home/Desktop/test.py pi@[raspberrypi_ip_address]:/home/pi`

## Extra references

- [Terminal and how to use it](https://magpi.raspberrypi.org/articles/terminal-help)
