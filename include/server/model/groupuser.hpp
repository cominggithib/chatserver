#ifndef GROUPUSER_H
#define GROUPUSER_H

#include "user.hpp"
// 群聊用户，多一个role角色信息，从User类直接继承，服用User的其他信息
// 这个类主要是当要显示用户信息时，还要显示role对象
// 继承于User
class GroupUser:public User
{
public:
    void setRole(string role) { this->role = role; }
    string getRole() { return this->role; }

private:
    string role;
};
#endif