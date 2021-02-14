# Week 8 Shorts

[Internet Primer](#internet-primer)  
[IP](#ip)  
[TCP](#tcp)  
[HTTP](#http)  
[HTML](#html)  
[CSS](#css)  
[JavaScript](#javascript)  
[DOM](#dom)  

## Internet Primer

An IP (IPv4) address is a sequence of 32 bits expressed in 4 groupsof decimal numbers: `w.x.y.z` each of them in the 0 to 255 range. This means that there can only be around 4 billion addresses. To solve this issue two things are used. One is to use private addresses. This means that multiple computers can share the same IP, but then the information is internally re-routed. More recently, IPv6 was released which uses 128 bits. There format is the same (groups of 4 decimals, each representing a hex). With this, we can have 340,282,366,920,938,463,463,374,607,431,768,211,456 different addresses (that's 340 undecillion, 282 decillion, 366 nonillion, 920 octillion, 938 septillion, 463 sextillion, 463 quintillion, 374 quadrillion, 607 trillion, 431 billion, 768 million, 211 thousand and 456 different addresses). IPv6 addresses have 8 clusters of 16 bits represented in hex.

`s:t:u:v:w:x:y:z`

When there's a lot of zeros collapsed into double colons: `::`. IP addresses are assigned by a DHCP (Dynamic Host Configuration Protocol). This is just a program that keps track of the addresses that it can assign and assigns them to devices that want to be connected.

**DNS** (Domain Name System) allows us to navigate by using human readable names. It translates names to IP addresses. There are multiple DNSes in the world, each serving their local area. Services like Google collect all the information and aggregate it.

**Access Points** is the network through which we connect to the internet, like your home network. In this scenario, only your home's router has an acctual public IP address that can connect to the internet. The router then assigns a private IP address to each device in your home network. This router is incharged of directing (ie routing) the information comming in and going out of the home network to the WWW.

The internt is just the set of rules (called protocols) that allow all the local networks to communicate between them.

## IP

The Internet Protocol (**IP**) controls how data is transmited between two points. Each network connects to a local **router**. The router contains a routing table that tells it where to go when it sees a specific address. Each router connects a local group of networks or routers to other networks or routers.

Data is separated into small packages. These packages are sent through the network with the data plus the instructions on how to re-assemble all the packages. Not all packages sent from point `A` to point `B` will take the same route.

## TCP

When sending information from point `A` to point `B`, if anything goes wrong along the way, TCP (Transmision Control Protocol) is responsible of re-requesting the missing pieces.

## HTTP


## HTML


## CSS



## JavaScript


## DOM

