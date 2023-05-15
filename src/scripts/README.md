## Features
* Create an AP (Access Point) at any channel.
* Choose one of the following encryptions: WPA, WPA2, WPA/WPA2, Open (no encryption).
* Hide your SSID.
* Disable communication between clients (client isolation).
* IEEE 802.11n & 802.11ac support
* Internet sharing methods: NATed or Bridged or None (no Internet sharing).
* Choose the AP Gateway IP (only for 'NATed' and 'None' Internet sharing methods).
* You can create an AP with the same interface you are getting your Internet connection.
* You can pass your SSID and password through pipe or through arguments (see examples).


## Dependencies
### General
* bash (to run this script) (#apt install bash )
* util-linux (for getopt) (#apt install util-linux)
* procps or procps-ng (#apt install procps)
* hostapd (#apt install hostapd )
* iproute2 (#apt install iproute2)
* iw (#apt install iw)
* iwconfig (you only need this if 'iw' can not recognize your adapter)
* haveged (optional)(#apt install haveged)

### For 'NATed' or 'None' Internet sharing method
* dnsmasq (#apt install dnsmasq)
* iptables (#apt install iptables)


## Installation
### Generic
    git clone https://github.com/dragonflyminipc/linux-wifi-hotspot
    cd linux-wifi-hotspot/src/scripts
    make install

### ArchLinux
    pacman -S create_ap

### Gentoo
    emerge layman
    layman -f -a jorgicio
    emerge net-wireless/create_ap

## Examples
### No passphrase (open network):
#xxx   create_ap wlan0 eth0 EQPAYMINER

### WPA + WPA2 passphrase:
    create_ap wlan0 eth0 EQPAYMINER Mini@123456

### AP without Internet sharing:
    create_ap -n wlan0 EQPAYMINER Mini@123456

### Bridged Internet sharing:
    create_ap -m bridge wlan0 eth0 EQPAYMINER Mini@123456

### Bridged Internet sharing (pre-configured bridge interface):
    create_ap -m bridge wlan0 br0 EQPAYMINER Mini@123456

### Internet sharing from the same WiFi interface:
    create_ap wlan0 wlan0 EQPAYMINER Mini@123456

### Choose a different WiFi adapter driver
    create_ap --driver rtl871xdrv wlan0 eth0 EQPAYMINER Mini@123456

### No passphrase (open network) using pipe:
    echo -e "EQPAYMINER" | create_ap wlan0 eth0

### WPA + WPA2 passphrase using pipe:
    echo -e "EQPAYMINER\nMini@123456" | create_ap wlan0 eth0

### Enable IEEE 802.11n
    create_ap --ieee80211n --ht_capab '[HT40+]' wlan0 eth0 EQPAYMINER Mini@123456

### Client Isolation:
    create_ap --isolate-clients wlan0 eth0 EQPAYMINER Mini@123456

## Systemd service
Using the persistent [systemd](https://wiki.archlinux.org/index.php/systemd#Basic_systemctl_usage) service
### Start service immediately:
    systemctl start create_ap

### Start on boot:
    systemctl enable create_ap




