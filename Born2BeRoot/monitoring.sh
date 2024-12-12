#!/bin/bash

#info on the architecture of the operating system and kernel version
arch_info=$(uname -a)

#number of physical processors (-c returns the count)
physical_processors=$(grep -c "processor" /proc/cpuinfo)

#the number of virtual processors
virtual_processors=$(nproc --all)

#available RAM and utilization rate
ram_info=$(free -m | grep "Mem" | awk '{print "available: "$7, ", percentage used: " $3/$2*100 "%"}')

#available storage and utilization rate
storage_info=$(df -h --total | grep "total" | awk '{print "available: " $4 ", percentage used: " $5 "%"}')

#CPU utilization rate.
cpu_utilisation=$(top -bn1 | grep "Cpu(s)" | awk '{print ($2 + $3) "%"}')

#date and time of the last reboot
last_reboot=$(who -b | awk '{print $3, $4}')

#check if LVM is active
lvm_status=$(lsblk | grep -q lvm && echo "LVM is active" || echo "LVM is not active")

#number of active connections
active_connections=$(netstat -tn | grep -c ESTABLISHED)

# Display the number of users using the server
user_count=$(who | wc -w)

# Display the IPv4 address and MAC address
ipv4=$(ip a | awk '/inet / && !/127.0.0.1/ {print $2}')
mac=$(ip link | awk '/ether/ {print $2}')

# Display the number of commands executed with sudo
sudo=$(grep -c "COMMAND" /var/log/sudo/sudo.log)


wall "  Architecture and Kernel Version: $arch_info
        Physical Processors: $physical_processors
        Virtual Processors: $virtual_processors
        RAM info: $ram_info
        Storage info: $storage_info
        CPU utilisation: $cpu_utilisation
        Last Reboot: $last_rebooti
        LVM Status: $lvm_status
        Active Connections: $active_connections
        Number of Users: $user_count
        IPv4 Address: $ipv4
        MAC info: $mac
        Sudo Commands Executed: $sudo"
