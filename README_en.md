# litechain

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/litechain.png" alt="litechain" width="256" height="256">

**English** | [中文](README_cn.md)  
#### Introduction  

Enabling embedded devices to be empowered by LLMS  
The basic communication is used to connect and construct a LangChain-like framework  
The underlying IO is invoked to implement the corresponding operation  


#### Software Architecture  
Three-tier architecture  
MCAL: Etherent(network port) CAN UART Flash RAM EEPROM Core(including interrupt and clock), etc., using the IC underlying library for standardized packaging  
MCAL: Etherent CAN UART Flash RAM EEPROM Core(including interrupt and clock), etc  
MODULE:Model_IO Retrieval Chains Memory Agents Callbacks  
APP: An application is composed of an application chain and its corresponding modules  

There are Plugins in each layer of the architecture, which can be third-party libraries or custom modules  

#### Development plan    

Implementation of chain:  

Context memory management:  

LAN LLM access:  
Local large model supporting the server program   

Implementation of cloud multi-model protocol:  
chatgpt  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/chatgpt.png" alt="chatgpt" width="256" height="128">  
chatgml  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/chatgml.png" alt="chatgpt" width="256" height="128">  
文心一言  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/wenxinyiyan.png" alt="chatgpt" width="256" height="128">   
通义千问  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/tongyiqianwan.png" alt="chatgpt" width="256" height="128">  


Hardware support:  
stm32f103+air742UG->4G  
esp32-c3->wifi  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/esp32.png" alt="合宙esp32 c3" width="256" height="256">  

Vector databases support:  
Milvus(remote storage matching)  

#### Installation   
/*TODO*/

#### Instructions  
/*TODO*/

#### Contribution  

1.  Fork the repository  
2.  Create Feat_xxx branch  
3.  Commit your code  
4.  Create Pull Request  


#### Gitee Feature  

1.  You can use Readme\_XXX.md to support different languages, such as Readme\_en.md, Readme\_zh.md  
2.  Gitee blog [blog.gitee.com](https://blog.gitee.com)  
3.  Explore open source project [https://gitee.com/explore](https://gitee.com/explore)  
4.  The most valuable open source project [GVP](https://gitee.com/gvp)  
5.  The manual of Gitee [https://gitee.com/help](https://gitee.com/help)  
6.  The most popular members  [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)  
