# <span style="font-size:45px;">litechain</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="https://github.com/jinxinyang/litechain/raw/master/images/litechain.png" alt="litechain" width="256" height="256">

**中文** | [English](README.md)
#### 介绍  
让嵌入式设备可以被LLM赋能  
使用基础通信进行连接,构造出类似langchain的框架  
调用底层IO来实现相应的操作  

#### 软件架构  
三层架构  
MCAL: Etherent(网口) CAN  UART  Flash  RAM  EEPROM Core(包含中断和时钟)等 ,使用IC底层库进行标准化封装  
MODULE:Model_IO(输入输出) Retrieval(检索) Chains(链) Memory(内存模块) Agents(代理) Callbacks(回调)   
APP: 应用链和对应的模块组合成应用  

每层架构中都会有个Plugins 可以是第三方库,也可以是自定义的模块  

#### 开发计划 

chain的实现:  

流式输出解析可以降低资源需求

单路COM接口->多路接口并发  

上下文内存管理:  

局域网LLM访问:  
本地大模型配套的服务端程序  

云端多模型协议实现:  
chatgpt  
<img src="https://github.com/jinxinyang/litechain/raw/master/images/chatgpt.png" alt="chatgpt" width="256" height="128">  
chatgml  
<img src="https://github.com/jinxinyang/litechain/raw/master/images/chatgml.png" alt="chatgpt" width="256" height="128">   
文心一言  
<img src="https://github.com/jinxinyang/litechain/raw/master/images/wenxinyiyan.png" alt="chatgpt" width="256" height="128">   
通义千问  
<img src="https://github.com/jinxinyang/litechain/raw/master/images/tongyiqianwan.png" alt="chatgpt" width="256" height="128">   

硬件支持计划:  
stm32f103+air742UG->4G  
esp32-c3->wifi  
[Test Project](https://github.com/jinxinyang/litechain-esp32_c3)    
<img src="https://github.com/jinxinyang/litechain/raw/master/images/esp32.png" alt="esp32 c3" width="256" height="256">  
Raspberry RP2040 ->RJ45   
<img src="https://github.com/jinxinyang/litechain/raw/master/images/RP2040.png" alt="RP2040" width="256" height="256">   

向量数据库支持:  
Milvus(远端存储匹配)  


硬件动作:  
print  
LED  


#### 安装教程  

/*TODO*/


#### 使用说明  
/*TODO*/


#### 参与贡献  

1.  Fork 本仓库  
2.  新建 Feat_xxx 分支  
3.  提交代码  
4.  新建 Pull Request  


