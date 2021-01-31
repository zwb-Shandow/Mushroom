## ZeroMQ

- 处理消息传输的库，组件

### 特征

1. 嵌入式的网络链接库
2. 用于大型高并发场景
3. 用于线程间，进程间，tcp，广播等
4. 构建多对多的连接模式 N：M      传统socket 1:1
5. io高吞吐，异步机制
6. 多语言支持，c接口

### 与socket区别

1. 与启动顺序无关
2. bind connect send recv函数实现
3. 无需处理拆包粘包问题，断线重连问题

### Zeromq模型

1. 请求回应模型 redis协议   请求的次序与回应的次序一一对应

- 请求端：send， recv
- 回复端：recv， send
- route + dealer device来实现

2. 管道模型 push pull
3. 监听发布者模型



### 提升

1. 数据结构 算法以及设计模式

红黑树  nginx进程管理  linux内核  openresty共享内存 epoll

2. 中间组件编程

数据库（mysql，redis， mongo）

nginx 过滤器 模块开发

Zeromq 构建大型分布式系统，多语言组成，多个worker

3. 网络io

- 网络模型 select ， poll， epoll
- 同步与异步
- 阻塞与非阻塞
- reactor   proactor



---



1. 多线程

- Pipe 管道  一端写，一段读 流向单一
- 队列
- 锁  互斥锁  条件变量  读写锁  cas  自旋锁  乐观锁  悲观锁

2. 多进程

- 共享内存 nginx 配置 openresty 中 shared_dict 实现进程间通信
- 管道  具有父子关系 fork
- 消息队列
- socket  建立连接、销毁连接、制定协议、选择协议（拆包粘包）、错误处理、断线重连、心跳检测、io epoll

