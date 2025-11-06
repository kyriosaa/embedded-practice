> NTUT Embedded Systems <br> Midterm Review <br> TCP/IP Networking

##
**1. What is an IP?**

> 32-bit, unique internet address of a host

##
**2. What is a Port?**

> 16-bit, unique identifier for specifying a process or service

##
**3. What is a MAC Address?**

> 48-bit, unique hardware identifier formatted as `XX:XX:XX:XX:XX:XX` and used for local data link layer communication. This number is burned into the hardware and cannot be changed.

##
**4. What are the 4 layers of the TCP/IP networking protocol?**

> 1. Link layer (device drivers)
> 2. Network layer (IP)
> 3. Transport layer (Port)
> 4. Application layer

##
**5. What is a Netmask?**

> A 32-bit number that "masks" an IP address to separate the Network ID from the Host ID.
> 255s correspond to the network while 0s correspond to the host.
>
> Example:
> IP Address: 192.168.1.101
> Netmask: 255.255.255.0
>
> This netmask tells the computer that the first three numbers identify the network and the last number identifies the specific device on that network.
> Any device with an IP address starting with `192.168.1` and the same netmask is considered to be on the same local network.

##
**6. What is Subnetting?**

> Subnetting is the process of taking one large network and dividing it into multiple smaller, logical sub-networks (or "subnets").
> We do this because it reduces network traffic, makes us able to apply security rules between subnets, and makes the network easier to manage by grouping related devices.

##
**7. How is Netmasking and Subnetting used together?**

> We can divide the host netmask to multiple subnets.
>
> Example:
> Subnet 1: Network ID `192.168.1.0` (Hosts from `.1` to `.126`)
> Subnet 2: Network ID `192.168.1.128` (Hosts from `.129` to `.254`)

##