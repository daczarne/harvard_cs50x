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

When sending information from point `A` to point `B`, if anything goes wrong along the way, **TCP** (Transmision Control Protocol) is responsible of re-requesting the missing pieces. It also handles transmiting the package to where it needs to go in the machine. TCP achieves this by sending the package to the **port** assigned to the program/utility/service that it's trying to send information to. Some of the ports are so commonly used that they have been standardized in computers:

- FTP (file transfer) uses port 21

- SMTP (e-mail) uses port 25

- DNS uses port 53

- HTTP (web browsing) uses port 80

- HTTPS (secure web browsing) uses port 443

## HTTP

The Hypertext Transfer Protocol, **HTTP**, is an application layer protocol that specifies how the web-page requests must be made from the client to the server, and from the server back to the client. Other protocols include

- **FTP:** File TransferPprotocol for how files are transfered

- **SMTP:** Simple Mail Transfer Protocol for how emails are sent

- **DDS:** Data Distribution Service

- **RPD:** Remote Desktop Protocol for remotly accessing a computer

- **XMPP:** Extensible Message and Presence Protocol for chat services

For example, to request the home page of `cats.com` the client would request

```
GET / HTTP/1.1
Host: cats.com
```

and the server would answer with

```
HTTP/1.1 200 OK
Content-type: text/html
```

where the 200 status code means that all is OK. Other codes exist to signal that things didn't work out as expected. In more general terms, an HTTP request line should inculde

```
method request-target http-version
```

The server will in turn respond with 

```
http-version status
```

Some status code are

| Class        | Code | Text                  | Comments                                       |
|--------------|------|-----------------------|------------------------------------------------|
| Success      | 200  | OK                    | All is well                                    |
| Redirection  | 301  | Moved Permanently     | Page is not at a new location                  |
| Redirection  | 302  | Found                 | Page we temporarily moved                      |
| Client Error | 401  | Unauthorized          | Page requires login credentials                |
| Client Error | 403  | Forbidden             | Server will not allow this request             |
| Client Error | 404  | Not found             | Server can not found what was asked for        |
| Server Error | 500  | Internal Server Error | Generic server failure                         |
| Server Error | 503  | Service unavailable   | Server is currently unable to handle request   |
| Server Error | 504  | Gateway timeout       | Server reached the waiting time for a response |
 
## HTML


## CSS



## JavaScript


## DOM

