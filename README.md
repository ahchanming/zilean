# zilean
#version 0.0.4
- 增加web模块
    - 增加浮层设置时间

#version 0.0.3
- configure server 配置的读取
	- getValue getIntValue
- threadPool 线程池模块
	- 基础线程池

#version 0.0.2
- 简单的网络层，网络层负责socket通信与信息解析
- dispatch层
- 实现在线用户统计CensusService


#version 0.0.1
- censusService统计服务器
- 客户端与服务器通信格式
	- length + code  + buff
	- 时间简单的通信，客户端发送一个TouchMessage,服务器返回一个RespTouchMessage

# 开发日志
提供提供一个简单的接口，客户端连接后，在日志上记录对应的信息。
与客户端连接使用socket连接，数据传输使用pb

- 前8个字符，用来表示操作，目前只支持一个操作touch
- 第9-16个字符，用来表示包的长度大小。
- 接下来是touch包的pb。
- touch数据格式
 - 用户id唯一表示，暂时传mac地址好了
 - 客户端数据版本，暂定为time
 - 时间戳 当前的时间（long）
 - 客户端版本
- touch操作之后，服务器打印对应的结果，并关闭链接。
- 客户端启动的时候进行一次touch操作，之后30分钟同步一次即可。
