<h1 align="center">
     BORN2BEROOT
</h1>
<h1 align="right"> <a name="up"></a>

<p align="center">
  <img width="600" height="400" src="https://user-images.githubusercontent.com/73075252/179326619-2aa4760f-0c65-41fd-9904-5129d77aec30.png">
</p>

<br>

## Table of Contents
1. [Description](#Description)
2. [Installation](#Installation)
3. [Commands](#Commands)

<br>

## Description
###### This project aims to introduce you to the wonderful world of virtualization.


| Skills |
| :--- |
| Rigor |
| Network & system administration |

<br>

## Installation


This is Debian 11, codenamed bullseye, netinst, for 64-bit PC (amd64) [Download](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-11.4.0-amd64-netinst.iso).

<br>

## Commands


**See the partition**:

```
# lsblk
```
<br>

**Be root**:

```
# su
```
<br>

**User add high level**:

```
# adduser <user_name>
```
<br>

**User add low level**:
```
# useradd <user_name>
```
<br>

**User delete**:
```
# deluser <username>
```
<br>

**See Groups**:
```
# getent group
```
```
# getent group <group_name>
```
<br>

**Group create**:
```
# groupadd <groupname>
```
<br>

**Group delete**:
```
# groupdel <groupname>
```
<br>

**See user groups**:
```
# groups <username>
```
<br>

**Adding users to groups**:
```
# usermod -aG <group_name> <user_name>
```
<br>

**Removing users from groups**:
```
# gpasswd --delete <user_name> <group_name>
```
<br>

**Install SSH**:
```
# apt install openssh-server
```
<br>

**SSH initialization**:
```
# systemctl start ssh 
# systemctl enable ssh
```
<br>

**SSH query**:
```
# systemctl status ssh
```
<br>

**#Port 22 -> Port 4242**
<br>
**#PermitRootLogin prohibit-password -> PermitRootLogin no**
```
# nano /etc/ssh/sshd_config
```
<br>

**SSH service restart**:
```
# service sshd restart
```
<br>

**Virtual Machine restart**:
```
# reboot
```
<br>

**Connect from physical machine**:
```
# ssh your_42user_name@localhost -p 4242
```
<br>

**Install UFW**:
```
# apt install UFW
```
<br>

**Deny all incoming requests.**:
```
# ufw default deny incoming
```
<br>

**Accept outgoing requests.**:
```
# ufw default allow outgoing
```
<br>

**Enable UFW**:
```
# ufw enable
```
<br>

**Check UFW**:
```
# ufw status 
```
```
# ufw status numbered (sequential rules)
```
<br>

**Allow port 4242**:
```
# ufw allow 4242
```
<br>

**Deny port 4242**:
```
# ufw deny 4242
```
<br>

**See all system information**:
```
# uname -a
```
<br>

**Change the Hostname**:
```
# hostnamectl set-hostname <new-name>
# vim /etc/hosts
$ 127.0.1.1 <new-name>
```
<br>

**Delete the allowed rule**:
```
# ufw delete allow 4242
```
<br>

**Delete disallowed rule**:
```
# ufw delete deny 4242
```
<br>

**Delete first Rule**:
```
# ufw delete 1
```
<br>

**Install Sudo**:
```
# apt install sudo
```
<br>

**Adding users to Sudo**:
```
# usermod -aG sudo <user_name>
```
<br>

**Let's open configuration file**:
```
# -sudo visudo -f /etc/sudoers.d
```
``
Defaults     passwd_tries=3
``
<br>
``
Defaults     badpass_message
``
<br>
``
Defaults     requiretty
``
<br>
``
Defaults     logfile="/var/log/sudo/sudo.log"
``
<br>
``
Defaults     log_input, log_output
``
<br>
``
Defaults     iolog_dir="/var/log/sudo/"
``
<br>
``
Defaults     secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
``
<br>
<br>

**Let's edit password policies**:
```
# nano /etc/login.defs
```

<br>

``
PASS_MAX_DAYS   30
``
<br>
``
PASS_MIN_DAYS   2
``
<br>
``
PASS_WARN_AGE   7
``
<br>
<br>

**See password policies**:
```
# chage -l <username>
# chage -l root
```
<br>

**Install password policies**:
```
# apt install libpam-pwquality
```
<br>

**Add password policies**:
```
# nano /etc/security/pwquality.conf
```

<br>

``
difok = 7
``
<br>
``
minlen = 10
``
<br>
``
dcredit= -1
``
<br>
``
ucredit= -1
``
<br>
``
enforce_for_root
``
<br>
``
enforcing= 1
``
<br>
``
maxrepeat= 3
``
<br>
``
usercheck = 1
``
<br>
``
dictcheck = 1
``
<br>
<br>

**Changing users password**:
```
# passwd root 
# passwd <user_name>
```
<br>

**Getting system information every 10 minutes**:
```
# crontab -u root -e
*/10 * * * * bash /your/monitoring.sh_path
```
<br>

**Open the Monitoring.sh**:
```
# vim /usr/local/sbin/monitoring.sh
```
<br>

**Edit file "Monitoring.sh"**:
```
ARCH=$(uname -a)
PCPU=$(cat /proc/cpuinfo | grep cpu\ cores | uniq | wc -l)
VCPU=$(cat /proc/cpuinfo | grep processor | wc -l)
CPUUSG=$(top -b -n1 | grep "Cpu(s)" | awk '{print($4)"%"}')
LASTBOOT=$(who -b | awk '{print $3,$4}')
lvmrtn=$(lsblk | grep "lvm" | wc -l)
LVMGET=$(if [ $lvmrtn -eq 0 ]; then echo no; else echo yes; fi)
TCPCNT=$(netstat | grep ESTABLISHED | wc -l)
TCPEST=$(netstat | grep ESTABLISHED | awk '{print($6)}')
USRCNT=$(who | wc -l)
NTWRKMAC=$(ip link show | grep link/ether | awk '{print($2)}')
NTWRKIP=$(hostname -I)
SUDOCNT=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
MEMUSG=$(free -m | grep Mem: | awk '{print($3)}')
MEMUSGTTL=$(free -m | grep Mem: | awk '{print($2)}')
MEMUSGPRCNT=$(free -m | grep Mem: | awk '{printf("%.2f"),($3/$2*100)}')
DSKUSGMB=$(df -BM --total | grep total | awk '{print($3)}' | tr -d M)
DSKUSGGB=$(df -BG --total | grep total | awk '{print($3)}' | tr -d G)
DSKUSGPRCNT=$(df --total | grep root | awk '{print($5)}')
wall "
        #Architecture: $ARCH
        #CPU physical : $PCPU
        #vCPU : $VCPU
        #Memory Usage: $MEMUSG/$MEMUSGTTL"MB" ($MEMUSGPRCNT"%")
        #Disk Usage: $DSKUSGMB/$DSKUSGGB"Gb" ($DSKUSGPRCNT)
        #CPU load: $CPUUSG
        #Last boot: $LASTBOOT
        #LVM use: $LVMGET
        #Connexions TCP : $TCPCNT $TCPEST
        #User log: $USRCNT
        #Network: "IP" $NTWRKIP ($NTWRKMAC)
        #Sudo : $SUDOCNT cmd
```
<br>

**See cron status**:
```
# sudo systemctl status cron
```
<br>

**Stop the cron**:
```
# sudo systemctl stop cron
```
<br>

**Disable the cron**:
```
# sudo systemctl disable cron
```
<br>

**Get disk signature**:
```
# shasum <your_virtual_machine>.vdi
```
<br>

|[ ⬆︎  Up](#up)|
|      :-:     |
