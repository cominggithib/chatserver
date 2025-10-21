# chatserver
ChatServer - 基于 Muduo 的分布式聊天系统
一个基于 C++ Muduo 网络库开发的分布式聊天服务器，支持用户注册、登录、好友管理、群组聊天和一对一实时通信。

核心特性
用户注册与登录认证
好友管理与在线状态
一对一实时聊天
群组聊天功能
Redis 发布订阅支持分布式部署
Nginx TCP 负载均衡
MySQL 数据持久化存储
离线消息存储

技术架构
网络框架: Muduo
数据库: MySQL
缓存/消息队列: Redis
负载均衡: Nginx Stream
数据格式: JSON

环境要求
Ubuntu/CentOS
MySQL 5.7+
Redis 5.0+
Nginx with Stream module
CMake 3.10+

编译运行
cd code/build
cmake ..
make
cd ../bin(可执行文件在bin里)
./ChatServer 127.0.0.1 6000
客户端连接
./ChatClient 127.0.0.1 6000



