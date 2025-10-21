#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <string>

using namespace std;

// 数据库操作类
class MySQL
{
public:
    // 初始化数据库链接
    MySQL();
    // 释放数据库链接资源
    ~MySQL();
    // 链接数据库
    bool connect();
    // 更新操作
    bool update(string sql);
    // 查询操作
    MYSQL_RES *query(string sql);
    //获取链接
    MYSQL* getConnection();
private:
    //相当于文件描述符
    MYSQL *_conn;// 这是一个指向MySQL连接结构的指针
};


#endif