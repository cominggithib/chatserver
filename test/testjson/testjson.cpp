#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//json序列化示例1
void func1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] =" hello,what are you doning";
    //实现将js->sendBuf
    string sendBuf = js.dump();
    cout<<js<<endl;
}
string func2(){
    json js;
    //添加数组
    js["id"]={1,2,3,4,5};
    //添加key-value
    js["name"] = "zhang san";
    //添加对象
    js["msg"]["zhang san"]= "hello world";
    js["msg"]["liu shuo"] = "hello china";
    cout << js<<endl;

    return js.dump();
}

string func3(){
    json js;
    //直接序列化一个vector
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    js["list"] = vec;

    //直接序列化一个map rongqi
    map<int,string> m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});
    js["path"] = m;
    //发送前先转为string,序列化为json字符串
    string sendBuf = js.dump();
    cout <<sendBuf <<endl;
    return sendBuf;
}
int main()
{
    // string recvBuf = func2();
    // json jsBuf=json::parse(recvBuf);

    // cout<< jsBuf["id"]<<endl;
    // auto arr = jsBuf["id"];
    // cout<<arr[3]<<endl;
    // func1();
    // func3();

    string recvBuf = func3();
    json jsBuf = json::parse(recvBuf);

    vector<int> vec = jsBuf["list"];

    for(int &v:vec){
        cout<<v<<" ";
    }
    return 0;
}