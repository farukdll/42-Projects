<h1 align="right"> <a name="up"></a>

# NetPractice
###### - NetPractice is a general practical exercise to let you discover networking.

<h1 align="center">
<p>
  <img width="750" alt="ETHERNET CABLE" src="https://user-images.githubusercontent.com/97880185/211422027-874250ac-aac1-4100-a5ae-dab275c34c31.png">
</p>
<br/>

</br>
<p>
  <img width="150" alt="Host" src="https://user-images.githubusercontent.com/97880185/211656437-609c2afe-8673-4b69-b960-9a8247a855c3.png">
  <img width="150" alt="Router" src="https://user-images.githubusercontent.com/97880185/211656451-11235c84-f555-427b-916e-93a428a816b9.png">
  <img width="150" alt="Switch" src="https://user-images.githubusercontent.com/97880185/211656464-3daa6f82-578b-4c6b-8d54-ff28b93e670f.png">
  <img width="130" alt="Internet" src="https://user-images.githubusercontent.com/97880185/211656370-91ad141f-d7c5-4877-8136-0f7f6237c646.png">
</p>
<br/>


### What are TCP/IP addresses and how do they work?
```     
- TCP/IP, in full Transmission Control Protocol/Internet Protocol,
  standard Internet communications protocols that allow digital computers to 
  communicate over long distances. 
```
### What is Transmission Control Protocol
```
- TCP guarantees the integrity of the data being communicated over a network.
  Before it transmits data, 
  TCP establishes a connection between source and destination,
  remains active until communication starts. 
  It then splits the large amount of data into smaller packets,
  It ensures end-to-end delivery without any data loss.
    
- TCP (Transmission Control Protocol) is a protocol that allows communication 
  between computers to be carried out in small packets and lossless. In fact,
  the most important feature of the TCP (Transmission Control Protocol) 
  protocol is that it performs the authentication and execution of the data 
  when sending or receiving data from the other party. 
  The TCP protocol was written to hide the losses that occur in 
  advanced computer networks.
```
### What is IP address
```
- IP addresses are the addresses required to connect to the internet.
  It is not possible for your device using the internet without an 
  IP address to connect to the internet.
  Thanks to IP addresses, computers find each other and perform data flow.
  Public IP and private IP addresses are used for this.
```
### IP address
</br>
<p>
  <img width="388" alt="388-321" src="https://user-images.githubusercontent.com/97880185/211622199-e08ab318-5964-4db3-af73-0df9475868af.png">
</p>

### What is a Public IP Address?
```
- The IP address that allows two computers to recognize each other is 
  called a public IP address.
  A public IP address is usually used to access the Internet. 
  With a public IP address,
  you can access your computer or other electronic devices remotely.
```
### Public IP address ranges
```
- 1 IP address can have up to 255 values.
- Returns to 0 after 255.

. 0 (binary: 00000000)
. 1 (binary: 00000001)
. 2 (binary: 00000010)
. 3 (binary: 00000011)
. ...
. ...
. ...
. 252 (binary: 11111100)
. 253 (binary: 11111101)
. 254 (binary: 11111110)
. 255 (binary: 11111111)

104.198.241.0 - 104.198.241.127

DECIMAL | 0 - 127
BINARY  | 0000000 - 1111111

- For example
             IP address | 104.198.241.125
             IP address | 01101000.11000110.11110001.01111101

- Public IP addresses cannot take values from private IP addresses, 
  they only take values different from private IP address values.
```
### What is a Private IP Address?
```
- The IP address that several devices create when they are connected to 
  each other wired or wirelessly is called a private IP address.
  Devices on this network are not assigned the same IP address.
  Each is assigned a different IP address and these IP addresses 
  cannot be repeated.
  Computers on different networks can use the same addresses.
  It's okay if they use the same address since they're on different networks.
  There is also an incentive to use private IP addresses to save data.
  With private IP addresses, 
  it is not possible to route or stream data from the internet.
  The assignment of these addresses is also not controlled by anyone.
```
### Private IP address ranges
`10.0.0.0    – 10.255.255.255 `<br>
`172.16.0.0  – 172.31.255.255 `<br>
`192.168.0.0 – 192.168.255.255`<br>
`127.0.0.0   – 127.255.255.255`
### What is Subnet Mask ?
  * ###### The Subnet Mask is a sequence of numbers used to distinguish between the network portion and the device portion of IP addresses.
  * ###### The subnet mask is used by network administrators and is used to group devices on a network, route IP addresses and create subnets.
  * ###### Subnet Mask refers to a sequence of numbers, usually consisting of four parts (for example, 255.255.255.255.0), that divides IP addresses into subnets. Each part is an 8-bit binary number, creating a 32-bit sequence of numbers in total.
  * ###### The Subnet Mask is important in IP addressing and network configuration and allows to route IP addresses more effectively and organize networks.
  
  
```
- DECIMAL
        IP address | 104.198.241.125
        Mask       | 255.255.255.128
  
- BINARY
        IP address | 01101000.11000110.11110001.01111101
        Mask       | 11111111.11111111.11111111.10000000
        
-BINARY  | 0000000 - 1111111
-DECIMAL | 0 - 255
```
### CIDR Notation (/24) (Classless Inter Domain Routing)
```
- The mask can also be represented with the Classless Inter-Domain Routing (CIDR). 
  This form represents the mask as a slash "/", followed by the number of 
  bits that serve as the network address.
  
  Therefore, the mask in the example above of 255.255.255.128, 
  is equivalent to a mask of /25 using the CIDR notation, 
  since 25 bits out of 32 bits represent the network address.
  
  -- Class A, B, C CIDR notation;

        Class A; 255.0.0.0 /8
        Class B; 255.255.0.0 /16
        Class C; 255.255.255.0 /24
        
 
 Special subnet masks for class A addresses
 
 Number of subnets    Number of bits        Subnet Mask      Number of hosts in each Subnet
  0                       1                    none                     none
  2                       2                 255.192.0.0               4,194,302
  6                       3                 255.224.0.0               2,097,150
  14                      4                 255.240.0.0               1,048,574
  30                      5                 255.248.0.0                 524,286
  62                      6                 255.252.0.0                 262,142
  126                     7                 255.254.0.0                 131,070
  254                     8                 255.255.0.0                  65,534
  
  
  
 Special subnet masks for class B addresses
  
 Number of subnets    Number of bits        Subnet Mask      Number of hosts in each Subnet
  0                       1                     none                     none
  2                       2                 255.255.192.0               16,382
  6                       3                 255.255.224.0                8,190
  14                      4                 255.255.240.0                4,094
  30                      5                 255.255.248.0                2,046
  62                      6                 255.255.252.0                1,022
  126                     7                 255.255.254.0                  510
  254                     8                 255.255.255.0                  254
  
  
  Special subnet masks for class C addresses
  
  Number of subnets   Number of bits        Subnet Mask      Number of hosts in each Subnet
   0                      1                     none                      none      
   1-2                    2               255.255.255.192                   62
   3-6                    3               255.255.255.224                   30
   7-14                   4               255.255.255.240                   14
   15-30                  5               255.255.255.248                    6
   31-62                  6               255.255.255.252                    2

```
### Masking-example
</br>
<p>
  <img width="389" alt="Mask" src="https://user-images.githubusercontent.com/97880185/211624489-1083a254-6f38-4aaa-866c-75d2d7092de6.png">
</p>

### Connection-switch
```
- A switch connects multiple devices together in a single network. 
  Unlike a router, the switch does not have any interfaces since it only 
  distributes packets to its local network, 
  and cannot talk directly to a network outside of its own.
```

### Switch-example
</br>
<p>
  <img width="389" alt="key" src="https://user-images.githubusercontent.com/97880185/211623839-3220c7ec-70da-49c7-a7c8-4ff54d877b6d.png">
</p>

### Router
```
- Just as the switch connects multiple devices on a single network, 
  the router connects multiple networks together. 
  The router has an interface for each network it connects to.

- Since the router separates different networks, 
  the range of possible IP addresses on one of its interfaces must 
  not overlap with the range of its other interfaces. An overlap in the 
  IP address range would imply that the interfaces are on the same network.
```
### Router-example
</br>
<p>
  <img width="400" alt="Router" src="https://user-images.githubusercontent.com/97880185/211625628-45dff831-f562-4934-b6ab-701dde3d5263.png">
</p>


### 10 questions in total
<details>
  <summary>Level 1</summary>
  <br>
  <img width="1223" alt="Level-1" src="https://user-images.githubusercontent.com/97880185/212213694-7524003c-d261-4f73-ae1b-df7a0012a9ac.png">
  <br> 
</details>

---
<details>
  <summary>Level 2</summary>
  <br>
  <img width="1223" alt="Level-2" src="https://user-images.githubusercontent.com/97880185/212213738-7536bda7-3bbf-4910-95d1-d689836d0856.png"> 
  <br>
</details>

---
<details>
  <summary>Level 3</summary>
  <br>
  <img width="1223" alt="Level-3" src="https://user-images.githubusercontent.com/97880185/212213866-f30c18c5-5ad7-4205-a0c1-b915e0293dcd.png">
  <br>
</details>

---
<details>
  <summary>Level 4</summary>
  <br>
  <img width="1223" alt="Level-4" src="https://user-images.githubusercontent.com/97880185/212213928-5cec0a99-ce40-4f20-89d7-2368cdde68ba.png">
  <br> 
</details>

---
<details>
  <summary>Level 5</summary>
  <br>
  <img width="1321" alt="Level-5" src="https://user-images.githubusercontent.com/97880185/212213967-74620659-7f35-40ef-ad5e-bf7c4d420045.png">
  <br>
</details>

---
<details>
  <summary>Level 6</summary>
  <br>
  <img width="1241" alt="Level-6" src="https://user-images.githubusercontent.com/97880185/212214010-98d800ca-b6af-4876-8bdd-6f95b66ce1b5.png">
  <br>
</details>

---
<details>
  <summary>Level 7</summary>
  <br>
  <img width="1419" alt="Level-7" src="https://user-images.githubusercontent.com/97880185/212214041-19c5b633-6f48-4a15-90e4-387a1a344180.png">
  <br> 
</details>

---
<details>
  <summary>Level 8</summary>
  <br>
  <img width="1126" alt="Level-8" src="https://user-images.githubusercontent.com/97880185/212214101-7c97ee4e-791d-454a-8a23-54a15be54024.png">
  <br>
</details>

---
<details>
  <summary>Level 9</summary>
  <br>
  <img width="1101" alt="Level-9" src="https://user-images.githubusercontent.com/97880185/212214179-ac1a2755-4994-46e4-bed1-a2fef5b4913f.png">
  <br>
</details>

---
<details>
  <summary>Level 10</summary>
  <br>
  <img width="1124" alt="Level-10" src="https://user-images.githubusercontent.com/97880185/212214241-bcca2d94-e5dd-4f18-a8be-eb9bc1b89794.png">
  <br>
</details>

---

|[ ⬆︎  Up](#up)|
|      :-:     |
