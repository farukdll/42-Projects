# KVIrc
![KVIrc-Logo](https://github.com/farukdll/Common-core/assets/97880185/16e5a386-4fd0-4d1d-a506-0499278168c4)

<!-- CONTRIBUTING -->
## Contributors
* [farukdll](https://github.com/farukdll)
* [Kaano1](https://github.com/Kaano1)
* [rasnesakam](https://github.com/rasnesakam)
* [b-tekinli](https://github.com/b-tekinli)

## Turkish Version of the README
* [Turkish Version](https://glitter-muskox-81c.notion.site/KVIrc-IRC-Projesi-Client-a1c59174db354bb4900ac76a8d7435d2)
## Table of Contents
<!-- <h3>Table of Contents</h3> -->

1. [What is KVIrc ?](#kvircc)
   * [KVIrc Protocols ?](#protocols)
2. [What is IRC ?](#irc)
   * [IRC Protocols ?](#protocols2)
3. [IRC Roadmap](#map)
4. [What is a Client ?](#client)
   * [Functions of a Client](#func)
   * [Client to Client (C2C)](#c2c)
   * [Client to Server (C2S)](#c2s)
   * [Server to Server (S2S)](#s2s)
5. [IRC Client Protocols — ( Channel Operators & Users ) & ( Commands )](#protocols3)
   * [Connection and Identity Authentication](#caia)
   * [Joining and Leaving a Channel](#jalac)
   * [Private and Channel Messages](#pacm)
   * [Operator Privileges](#op)
   * [The OPER Command](#toc)
   * [The MODE Command (Channel Operator Privileges)](#tmccop)
   * [User Modes](#um)
   * [MODE Command (User Modes)](#mcum)
   * [Changing Nickname](#cn)
   * [Ping-Pong Mechanism](#ppm)
   * [Commands and Replies](#car)
   * [Listing Channels](#lc)
   * [NOTICE Command](#nc)
   * [Usage of the NOTICE Command](#uotnc)
   * [Example Usage of NOTICE](#euon)
7. [KVIrc PREFIX ?](#kp)
   * [What is PREFIX on an IRC Server ?](#wipoais)
   * [KVIrc PREFIX Other Details You Should Know ?](#kpodysk)
8. [What is Socket Programming ?](#wisp)
9. [What Are Internet Protocols ?](#waip)
10. [What is the Difference Between TCP and UDP ?](#witdbtau)
11. [Sockets and Their Types :](#satt)
12. [Used Functions :](#uf)
13. [What is Netcat ?](#win)
14. [What is a Vector ?](#wiav)
15. [Commands :](#cmd)


<!-- <summary>Table of Contents</summary> -->
<!--
<ol>
  <li><a href="#.">...</a></li>
  <li><a href="#.">...</a></li>
  <li><a href="#.">...</a></li>
  <li><a href="#.">...</a></li>
  <li><a href="#.">...</a></li>
  <li><a href="#.">...</a></li>
</ol>
</details>
-->
-------------------------------------------------------------------------------------

### What is KVIrc ? <a name="kvircc"></a>
![what is kvırc](https://github.com/farukdll/Common-core/assets/97880185/9109648e-2032-4ff6-8c14-ec122bde68bd)

### KVIrc Protocols ? <a name="protocols"></a>
![kvırc pro](https://github.com/farukdll/Common-core/assets/97880185/d8766de3-4050-4b3d-9259-85856fd32dee)

-------------------------------------------------------------------------------------

### What is IRC ? <a name="irc"></a>
![what is irc](https://github.com/farukdll/Common-core/assets/97880185/e0f176d2-ca0e-497e-8cae-dbef57a47068)

### IRC Protocols ? <a name="protocols2"></a>
![IRC Protokols](https://github.com/farukdll/Common-core/assets/97880185/2f7b3c8d-5264-42a6-a735-4ee449efc1a8)

-------------------------------------------------------------------------------------

### IRC Roadmap <a name="map"></a>
![Roadmap](https://github.com/farukdll/Common-core/assets/97880185/209fe5ba-52ff-4277-92e4-ed1859d2e471)

<img width="800" alt="map" src="https://github.com/farukdll/Common-core/assets/97880185/9e5f335d-ec94-4e0b-8b3f-e453a3cf668e">

-------------------------------------------------------------------------------------

### What is a Client ? <a name="client"></a>
![what is a client ](https://github.com/farukdll/Common-core/assets/97880185/20322d58-a7cf-49b7-9c2e-2a6de6306a82)

### Functions of a Client <a name="func"></a>
![func  of a client ](https://github.com/farukdll/Common-core/assets/97880185/c89a17d6-c006-41c3-a9f5-2da46ea616c5)

### Client to Client (C2C) <a name="c2c"></a>
![c2c](https://github.com/farukdll/Common-core/assets/97880185/de396599-6aab-4c8b-a4c7-ff721fff3636)

### Client to Server (C2S) <a name="c2s"></a>
![c2s](https://github.com/farukdll/Common-core/assets/97880185/0850096f-8743-4b24-b16b-5abe5c9c7d63)

### Server to Server (S2S) <a name="s2s"></a>
![s2s](https://github.com/farukdll/Common-core/assets/97880185/23b13100-da2b-4aa3-997e-69419ad3f43d)

-------------------------------------------------------------------------------------

### IRC Client Protocols — ( Channel Operators & Users ) & ( Commands ) <a name="protocols3"></a>

### Connection and Identity Authentication <a name="caia"></a>
![caia](https://github.com/farukdll/Common-core/assets/97880185/0193fb54-bac9-40a4-8489-82fd67e5243e)

### Joining and Leaving a Channel <a name="jalac"></a>
![jalac](https://github.com/farukdll/Common-core/assets/97880185/d201c5d8-b468-468a-8a12-2965e05a5de5)

### Private and Channel Messages <a name="pacm"></a>
![pacm](https://github.com/farukdll/Common-core/assets/97880185/258b0f91-1fd5-4dcc-b61a-f4386dea3ed9)

### Operator Privileges <a name="op"></a>
![op](https://github.com/farukdll/Common-core/assets/97880185/56c3ef6e-8b35-41fb-b5ac-2d8a04094f7f)

### The OPER Command <a name="toc"></a>
![toc](https://github.com/farukdll/Common-core/assets/97880185/85b817cd-3fc6-44ec-9e5c-a95b97e061a6)

### The MODE Command (Channel Operator Privileges) <a name="tmccop"></a>
![tmccop](https://github.com/farukdll/Common-core/assets/97880185/b87fa41c-1640-46bd-8bee-415d197a381d)

### User Modes <a name="um"></a>
![um](https://github.com/farukdll/Common-core/assets/97880185/9fdc8e0b-7461-474b-8e67-065de43bf967)

### MODE Command (User Modes) <a name="mcum"></a>
![mcum](https://github.com/farukdll/Common-core/assets/97880185/ef48af23-afe9-4d56-8c61-36a08052d3bc)

### Changing Nickname <a name="cn"></a>
![cn](https://github.com/farukdll/Common-core/assets/97880185/e53b66db-b2e4-4bb6-89c5-6dde65bdfe20)

### Ping-Pong Mechanism <a name="ppm"></a>
![ppm](https://github.com/farukdll/Common-core/assets/97880185/03e7be3e-b855-4ba8-8db9-76f75278d9f0)

### Commands and Replies <a name="car"></a>
![car](https://github.com/farukdll/Common-core/assets/97880185/68f30443-631b-46b9-83d8-c1ff6b079eaa)

### Listing Channels <a name="lc"></a>
![lc](https://github.com/farukdll/Common-core/assets/97880185/37df267d-1e85-4227-a06c-2e635488764d)

### NOTICE Command <a name="nc"></a>
![nc](https://github.com/farukdll/Common-core/assets/97880185/133a37e1-3353-4f06-b3a8-f3e423685d4b)

### Usage of the NOTICE Command <a name="uotnc"></a>
![uotnc](https://github.com/farukdll/Common-core/assets/97880185/04f8f7f2-1cd8-4abf-bf4a-408fe6d1fc8a)

### Example Usage of NOTICE <a name="euon"></a>
![euon](https://github.com/farukdll/Common-core/assets/97880185/2df54ab0-96b3-404c-bb5c-47cdf015f82c)

-------------------------------------------------------------------------------------

### KVIrc PREFIX ? <a name="kp"></a>
![kp](https://github.com/farukdll/Common-core/assets/97880185/6110e949-cb50-4a31-842b-7e137db8950e)

### What is PREFIX on an IRC Server ? <a name="wipoais"></a>
![wipoais](https://github.com/farukdll/Common-core/assets/97880185/013584e9-9769-4810-b1fa-727d97255bf9)

### KVIrc PREFIX Other Details You Should Know ? <a name="kpodysk"></a>
![kpodysk](https://github.com/farukdll/Common-core/assets/97880185/a3fb4e46-f1d4-42b5-8046-6f4da44f3bae)

-------------------------------------------------------------------------------------

### What is Socket Programming ? <a name="wisp"></a>
![wisp](https://github.com/farukdll/Common-core/assets/97880185/d05e8054-b138-4df1-a5ed-81b683c5de7a)

### What Are Internet Protocols ? <a name="waip"></a>
![waip](https://github.com/farukdll/Common-core/assets/97880185/f3055799-9981-4da2-97da-e33b6e07d9fd)

### What is the Difference Between TCP and UDP ? <a name="witdbtau"></a>
![witdbtau](https://github.com/farukdll/Common-core/assets/97880185/175b83c0-ba6d-4c64-abcf-69c43f534bf9)

### Sockets and Their Types <a name="satt"></a>
![satt](https://github.com/farukdll/Common-core/assets/97880185/8cc8b7f0-953f-47e0-8180-ec2d7146a005)

-------------------------------------------------------------------------------------

### Used Functions : <a name="uf"></a>
```cpp
socket(AF_INET, SOCK_STREAM, 0);
```
![1](https://github.com/farukdll/Common-core/assets/97880185/6c5a4eda-e329-4d02-8dfd-4a172834813b)
```cpp
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
![2](https://github.com/farukdll/Common-core/assets/97880185/b5e20f7f-dc42-4422-9ce0-c0f74b6e9a37)
```cpp
listen(int sockfd, int backlog);
```
![3](https://github.com/farukdll/Common-core/assets/97880185/6a720bee-1692-4388-ad57-28340b237950)
```cpp
accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
![4](https://github.com/farukdll/Common-core/assets/97880185/6a48584c-5370-491e-b893-60c5c638c19d)
```cpp
#include <netinet/in.h>

struct sockaddr_in {
	short			sin_family;        // AF_INET
	unsigned short   sin_port;	 // htons(3490)
	struct in_addr   sin_addr;	 // see struct in_addr, below
	char			 sin_zero[8];      // zero this if you want to
};

struct in_addr {
	unsigned long s_addr;        // load with inet_aton()
};
```
![5](https://github.com/farukdll/Common-core/assets/97880185/92f1e8a1-919e-4b2e-8ec7-9d73e87611f1)
![6](https://github.com/farukdll/Common-core/assets/97880185/350b7cca-389b-4528-9514-06ba9d4d0f52)
![7](https://github.com/farukdll/Common-core/assets/97880185/a2280db7-c46a-4121-a446-9e427d866e35)
```cpp
int inet_pton(int af, const char *src, void *dst);
```
![8](https://github.com/farukdll/Common-core/assets/97880185/1b86911a-8f15-49fb-94dc-a436714143d2)
```cpp
#include <string>

int main() {
	std::string str = "Merhaba";

	const char* cstr = str.c_str();

	// C-style karakter dizisini kullanma
	// ...
	return 0;
}
```
![9](https://github.com/farukdll/Common-core/assets/97880185/8de0421f-def0-49a4-a6b0-e874ac47a06c)
```cpp
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```
![10](https://github.com/farukdll/Common-core/assets/97880185/743fa579-770d-42c3-9806-54daef8d58e6)
![11](https://github.com/farukdll/Common-core/assets/97880185/5ab95673-1351-4ff2-8465-69f2bcfca45c)
```cpp
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```
![12](https://github.com/farukdll/Common-core/assets/97880185/865835a5-d50d-4b5b-85f8-e1a69a60e77d)

-------------------------------------------------------------------------------------

### What is Netcat ? <a name="win"></a>
![win](https://github.com/farukdll/Common-core/assets/97880185/8e0baa3e-e9bc-4345-b003-88cbb378f9b6)

### What is a Vector ? <a name="wiav"></a>
![wiav](https://github.com/farukdll/Common-core/assets/97880185/bca28967-9ff9-4776-bc55-1235f5917bcb)
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    for (int i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    return 0;
}
```

-------------------------------------------------------------------------------------

### Commands : <a name="cmd"></a>
![cmd](https://github.com/farukdll/Common-core/assets/97880185/5e8f4390-90b2-4aed-be85-62bfefda887c)

-------------------------------------------------------------------------------------
