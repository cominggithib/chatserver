#ifndef USER_H //// 如果没有定义 USER_H 这个宏
#define USER_H// 那么就定义 USER_H 这个宏
#include <string>
using namespace std;

//映射数据库的类
//匹配User表的ORM类
class User{
public:
    User(int id = -1,string name ="", string pwd = "",string state = "offline")
    {
        this->id = id;
        this->name = name;
        this->password = pwd;
        this->state = state;
    }
    //设置方法
    void setId(int id){this->id = id;}
    void setName(string name){this->name = name;}
    void setPwd(string pwd){this->password = pwd;}
    void setState(string state){this->state = state;}
    //获取方法
    int  getId(){return this->id;}
    string getName(){return this->name;}
    string getPwd(){return this->password;}
    string getState(){return this->state;}
//基类的私有成员设置为protected，是为了让派生类能够访问这些成员，同时仍然对外部世界保持封装。
protected:
    int id;
    string name;
    string password;
    string state;
};

#endif // 结束条件编译