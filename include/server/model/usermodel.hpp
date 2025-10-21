// 数据库操作类,进行数据操作
// 是User这张表的具体业务类

#ifndef USERMODOL_H
#define USERMODOL_H

#include "user.hpp"
// User表的数据操作类
class UserModel
{
public:
    // User表的增加方法
    bool insert(User &user);
    //根据用户id查询用户信息
    User query(int id);
    //更新用户的状态信息
    bool updateState(User user);

    //重置用户的状态信息
    void resetState();
};
#endif