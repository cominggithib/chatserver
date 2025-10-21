//#include "db.h"
#include "server/db/db.h"
#include <muduo/base/Logging.h>

// 数据库配置信息
static string server = "127.0.0.1";
static string user = "root";
static string password = "123456";
static string dbname = "chat";

// 初始化数据库链接
MySQL::MySQL()
{
    _conn = mysql_init(nullptr);
}

// 释放数据库链接资源
MySQL::~MySQL()
{
    if (_conn != nullptr)
    {
        mysql_close(_conn);
    }
}

// 链接数据库
bool MySQL::connect()
{
    //_conn是MySQL链接句柄
    MYSQL *p = mysql_real_connect(_conn, server.c_str(), user.c_str(),
                                  password.c_str(), dbname.c_str(), 3306, nullptr, 0);
    if (p != nullptr)
    {
        // 兼容中文
        // C/C++代码默认的编码字符是ASCII，如果不设置为gbk，从mysql上拉到客户端时中文会显示乱码或？
        mysql_query(_conn, "set names gbk");
        LOG_INFO << "connect mysql success!";
    }
    else
    {
        LOG_INFO << "connect mysql fail!";
    }
    return true;
}

// 更新操作
bool MySQL::update(string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":" << sql << "更新失败";
        return false;
    }
    return true;
}

// 查询操作
MYSQL_RES* MySQL::query(string sql)
{
    //使用连接,所有后续的数据库操作都通过这个句柄进行mysql_query
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":" << sql << "查询失败";
        return nullptr;
    }
    return mysql_use_result(_conn);
}

    //获取链接
MYSQL* MySQL::getConnection()
{
    return _conn;
}