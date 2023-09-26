# <span style="font-size:45px;">litechain</span>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/litechain.png" alt="litechain" width="256" height="256">

**中文** | [English](README_en.md)
#### 介绍  
让嵌入式设备可以被LLM赋能  
使用基础通信进行连接,构造出类似langchain的框架  
调用底层IO来实现相应的操作  

#### 软件架构  
四层架构 
HAL:针对不芯片型号的驱动,统一放在对应的MCAL的文件夹下面  
MCAL: Etherent(网口) CAN  UART  Flash  RAM  EEPROM Core(包含中断和时钟)等  
MODULE:Model_IO(输入输出) Retrieval(检索) Chains(链) Memory(内存模块) Agents(代理) Callbacks(回调)   
APP: 应用链和对应的模块组合成应用  

每层架构中都会有个Plugins 可以是第三方库,也可以是自定义的模块  

#### 开发计划和素材  
chain的实现:  

上下文内存管理:  
http协议统一接口  

局域网LLM访问:  
本地大模型配套的服务端程序  

云端多模型协议实现:  
chatgpt  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/chatgpt.png" alt="chatgpt" width="256" height="128">  
chatgml  
文心一言  
通义千问  

硬件支持:  
stm32f103+air742UG->4G  
esp32 c3->wifi  
<img src="https://gitee.com/jinxinyang/litechain/raw/master/images/esp32.png" alt="合宙esp32 c3" width="562" height="413">  

向量数据库支持:  
Milvus(远端存储匹配)  


硬件动作:  
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


#### 特技    

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md  
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)  
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目  
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目  
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)  
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)  
