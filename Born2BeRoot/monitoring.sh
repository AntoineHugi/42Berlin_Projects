#!/bin/bash

# Display the architecture of the operating system and kernel version
arch_info=$(uname -a)

# Display the number of physical processors
physical_processors=$(grep -c '^processor' /proc/cpuinfo)

# Display the number of virtual processors
virtual_processors=$(nproc --all)

# Display the available RAM and utilization rate
ram_info=$(free -m | awk '{print $7, $3*100/$2 }')

# Display the available storage and utilization rate
storage_info=$(df -h --total | awk '{print $1, $3, $2, $5}')

# Display the CPU utilization rate, need to simplify code.
cpu_utilisation=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{printf "CPU Utilization: %.2f%%", 100 - $1}')

# Display the date and time of the last reboot
last_reboot=$(who -b | awk '{print $3, $4, $5}')

# Check if LVM is active
lvm_status=$(lsblk | grep -q lvm && echo "LVM is active" || echo "LVM is not active")

# Display the number of active connections
active_connections=$(netstat -tun | grep -c ESTABLISHED)

# Display the number of users using the server
user_count=$(who | wc -l)

# Display the IPv4 address and MAC address
ipv4_info=$(ip a | awk '/inet / && !/127.0.0.1/ {print "IPv4 Address: "$2}')
mac_info=$(ip a | awk '/ether/ {print "MAC Address: "$2}')

# Display the number of commands executed with sudo
sudo_command_count=$(grep -c "COMMAND" /var/log/sudo.log 2>/dev/null || echo "0")


wall "  Architecture and Kernel Version: $arch_info
        Physical Processors: $physical_processors
        Virtual Processors: $virtual_processors
        RAM info: $ram_info
        Storage info: $storage_info
        CPU utilisation: $cpu_utilisation
        Last Reboot: $last_reboot
        LVM Status: $lvm_status
        Active Connections: $active_connections
        Number of Users: $user_count
        IPv4 Address: $ipv4_info
        MAC info: $mac_info
        Sudo Commands Executed: $sudo_command_count"