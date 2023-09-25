# litechain

#### 介绍
让嵌入式设备可以被LLM赋能  
使用基础通信方式封装出兼容langchain接口的工具  
调用底层IO来实现相应的操作  

#### 软件架构
三层架构  
MCAL: Etherent(网口) CAN  UART  Flash  RAM  EEPROM Core(包含中断和时钟)等  
MODULE:Model_IO(输入输出) Retrieval(检索) Chains(链) Memory(内存模块) Agents(代理) Callbacks(回调)  
APP: 应用链和对应的模块组合成应用

每层架构中都会有个Plugins 可以是第三方库,也可以是自定义的模块 

#### 开发计划和素材
chain的实现

上下文内存管理

局域网LLM访问:
CAN-使用UDS的31服务(例程号使用0xFF03-0xFFFF)来实现


socket转http

云端多模型协议实现



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
