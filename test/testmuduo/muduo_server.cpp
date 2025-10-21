/*
mudouo网络ku给ronghu提供了两个主要的类
TcpServer ：用于编写服务器程序
TcpClient ：用于编写客户端程序

epoll+线程池
好处：把网络I/O的代码和业务代码区分kai
业务代码只需要关注用户的连接和断开，用户的ke读写事件
*/

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <functional> //使用绑定器
#include <iostream>
#include <string>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

/*基于muduo网络库开发服务器程序
第一步：组合TcpServer对象
第二步：创建EventLoop事件循环对象的指针
第三步：明确TcpServer构造函数需要什么参数，输出ChatServer的构造函数,因为只有一个默认的构造函数
，需要自己指定怎么构造
第四步：在当前fuwuqi类的构造函数当中，注册处理连接的回调函数和处理读写事件的回调函数
第五步：设置合适的fuwu端线程数量,muduo会自己分配I/O线程和worker线程
*/
class ChatServer
{
public:
    ChatServer(EventLoop *loop,               // 事件循环
               const InetAddress &listenAddr, // IP+Port
               const string &nameArg)         // fuwuqi名字
        : _server(loop, listenAddr, nameArg), _loop(loop)
    {
        // 给服务器注册用户连接的创建和断开回调,当底层监听到有用户的断开连接是，调用onConnection函数
        _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1)); //_1是占位fu

        // 给服务器注册用户读写事件
        _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3)); // onMessage有三个参数，需要三个占位fu

        // 设置fuwuqi端的线程数量，ruguo设置两个，会自动给io线程一个，给工作线程一个
        _server.setThreadNum(4); // 一个I/O线程，三个worker线程,第五步

        // kaiqi事件循环
    }
    void start()
    {
        _server.start();
    }

private:
    // 专门处理用户的连接创建和断开 epoll listenfd accept
    void onConnection(const TcpConnectionPtr &conn)
    {
        if (conn->connected())
        {
            cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << "state::online" << endl;
        }
        else
        {
            cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << "state::outline" << endl;
            conn->shutdown();//相当于close(fd)
            //_loop->quit();这句是结束server
        }
    }
    // 专门处理用户的读写事件
    void onMessage(const TcpConnectionPtr &conn, // 连接
                   Buffer *buffer,                  // 缓冲区
                   Timestamp time)               // 接收到数据的事件信息
    {
        string buf = buffer->retrieveAllAsString();
        cout<< "recv data:"<<buf<<"time:"<<time.toString() << endl;
        conn->send(buf);//收到什么fasong什么，发送给当前连接的对端
    }
    TcpServer _server; // 第一步
    EventLoop *_loop;  // 第二步
};

int main()
{
    EventLoop loop;//epoll
    InetAddress addr("127.0.0.1",8000);//127.0.0.1这个地址只能用于本机回环，也就是使用其他的电脑要用虚拟ip地址
    ChatServer server(&loop,addr,"ChatServer");//给服务器name

    server.start();//将listenfd通过epoll_ctl变为epoll
    loop.loop(); // epoll_wait以阻塞方式等待新用户连接，以连接用户的读写事件等

    return 0;
}