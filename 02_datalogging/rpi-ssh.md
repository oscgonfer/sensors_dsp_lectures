# Connect to your Pi via SSH

## Activate SSH

### Without a monitor and keyboard

1. Make sure Raspbian is properly installed on your SD card
2. Read the SD card content with your laptop and navigate to the boot folder (this is the root folder of your SD card).
3. Create a new empty file and name it `ssh` (without an extension)
4. Safely remove your SD card from your laptop and insert it again in your Pi
5. Boot up your Pi, you should have SSH enabled

### With a monitor and keyboard

#### GUI

1. Boot up your Pi
2. Preferences >  Raspberry Pi Configuration > interfaces > Enable SSH

#### Terminal

1. Boot up your Pi and open the terminal
2. type `sudo raspi-config`
3. navigate to `Interfacing options` > `ssh` > yes


## Know your IP address

1. Open the terminal and type `hostname -l`. You should see your IP address there.

## Set a new password

On Raspbian, default username is `pi` and password is `raspberry`. You may want to set a new and personal password for security reasons. To do so:

1. Open the terminal and type `passwd`
2. Follow the instructions

## Access your Pi via SSH

1. Open the terminal
2. type: `ssh pi@[raspberrypi_ip_address]`
3. Type your password
4. You are in!


## Extra references

- [Terminal and how to use it](https://magpi.raspberrypi.org/articles/terminal-help)