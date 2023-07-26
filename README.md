## Linux Wifi Hotspot

<!-- [![Build Status](https://travis-ci.com/lakinduakash/linux-wifi-hotspot.svg?branch=master)](https://travis-ci.com/lakinduakash/linux-wifi-hotspot) -->
![Build](https://github.com/lakinduakash/linux-wifi-hotspot/actions/workflows/build.yml/badge.svg)
[![Gitter](https://badges.gitter.im/linux-wihotspot/community.svg)](https://gitter.im/linux-wihotspot/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Flakinduakash%2Flinux-wifi-hotspot.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Flakinduakash%2Flinux-wifi-hotspot?ref=badge_shield)

### What's new
* Share wifi via QR code
* UI improvements
* Show the connected devices
* Able to customize gateway address from GUI

### Features
 
* Share your wifi like in Windows - Use wifi and enable hotspot at the same time.
* Share a wifi access point from any network interface
* Share wifi via QR code
* MAC filter
* View connected devices
* Includes Both command line and gui.
* Support both 2.4GHz and 5GHz (Need to be compatible with your wifi adapter). Ex: You have connected to the 5GHz network and share a connection with 2.4GHz.
* Customise wifi Channel, Change MAC address, etc.
* Hide SSID
* customize gateway IP address
* Enable IEEE 80211n, IEEE 80211ac modes

![screenshot](docs/sc4.png)


### Command line help and documentation

Read [Command line help and documentation here](src/scripts/README.md).

If you only need the command-line without GUI run `make install-cli-only` as root user.

### Notes

- Sometimes there are troubles with **5Ghz bands** due to some vendor restrictions. If you cannot start hotspot while you are connected to 5Ghz band, Unselect **Auto** and select **2.4Ghz** in frequency selection.

- If any problems with **RealTeK Wifi Adapters** see [this](docs/howto/realtek.md)

- **Unable to allocate IP: firewalld issue:** Please check for potential fixes: [#209](https://github.com/dragonflyminipc/linux-wifi-hotspot/issues/209) [#166](https://github.com/dragonflyminipc/linux-wifi-hotspot/issues/166)

- **dnsmasq: cannot read /tmp/create_ap.wlo1.conf.*****/dnsmasq.conf: Permission denied**, on Manjaro or ArchLinux ; check [#183](https://github.com/dragonflyminipc/linux-wifi-hotspot/issues/183)

## Installation

#### Debian/Ubuntu

Download the debian package from latest [release](https://github.com/dragonflyminipc/linux-wifi-hotspot/releases/latest)

**OR**

```bash
# For ubuntu only
sudo add-apt-repository ppa:dragonflyminipc/lwh
OR
sudo add-apt-repository ppa:lakinduakash/lwh
sudo apt install linux-wifi-hotspot

```

#### Arch based distributions

Linux Wifi Hotspot is available as an [AUR package](https://github.com/dragonflyminipc/linux-wifi-hotspot/). You can install it manually or with your favourite AUR helper.  
For example, if you use `yay` you can do:  
`yay -S linux-wifi-hotspot`

## Dependencies

#### General
* bash
* util-linux (for getopt)
* procps or procps-ng
* hostapd
* iproute2
* iw
* iwconfig (you only need this if 'iw' can not recognize your adapter)
* haveged (optional)

_Make sure you have those dependencies by typing them in terminal. If any of dependencies fail
install it using your distro's package manager_

#### For 'NATed' or 'None' Internet sharing method
* dnsmasq
* iptables

#### To build from source

* make
* gcc and g++
* build-essential
* pkg-config
* gtk
* libgtk-3-dev
* libqrencode-dev (for qr code generation)
* libpng-dev (for qr code generation)

On Ubuntu or debian install dependencies by,

```bash
sudo apt install -y libgtk-3-dev build-essential gcc g++ pkg-config make hostapd libqrencode-dev libpng-dev
```

On Fedora/CentOS/Red Hat Enterprise Linux/Rocky Linux/Oracle Linux
```bash
sudo dnf install -y gtk3-devel gcc gcc-c++ kernel-devel pkg-config make hostapd qrencode-devel libpng-devel
```

## Installation

    git clone https://github.com/dragonflyminipc/linux-wifi-hotspot
    cd linux-wifi-hotspot

    #build binaries
    make

    #install
    sudo make install
    
## Uninstallation
    sudo make uninstall
    
## Running
You can launch the GUI by searching for "Wifi Hotspot" in the Application Menu
or using the terminal with:

    wihotspot

## Run on Startup
The `wihotspot` GUI uses `create_ap` to create and manage access points. 
Start the hotspot service on startup (using your saved configuration) with:

    cd linux-wifi-hotspot/src/scripts
    make install

    systemctl enable create_ap    
    create_ap -m bridge wlan0 eth0 MyAccessPoint MyPassPhrase
    create_ap wlan0 wlan0 MyAccessPoint MyPassPhrase
    systemctl start create_ap
    
## Disabled
The `wihotspot` GUI uses `create_ap` to disabled and manage access points. It still untested:

    systemctl disable create_ap

## Contributing

If you found a bug or you have an idea about improving this make an issue. Even a small contribution make open source world more beautiful.
Please read [CONTRIBUTING.md](CONTRIBUTING.md) for more info.

## Disclaimer
<div>Icons made by <a href="https://www.fnfdesk.com" title="FNFDESK">FNFDESK</a> from <a href="https://www.fnfdesk.com/" title="FNFDESK">www.fnfdesk.com</a></div>



## License
FreeBSD

Copyright (c) 2013, oblique

Copyright (c) 2021, lakinduakash

Copyright (c) 2023, Dragonfly


