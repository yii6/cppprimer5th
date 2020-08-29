/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.6
History
    version 1.0 2016.10.16
*/
#include <typeinfo>
#include <iostream>
using namespace std;
class A {
public:
    A()=default;
    virtual ~A() {
    }
};
class B:public A {
public:
    B()=default;
    virtual ~B() {
    }
};
class C:public B {
public:
    C()=default;
    virtual ~C() {
    }
};
int main() {
    A *pa=new C;
    cout<<typeid(*pa).name()<<endl;
    C cobj;
    A &ra=cobj;
    cout<<typeid(ra).name()<<endl;
    B *pb=new B;
    A &ra1=*pb;
    cout<<typeid(&ra1).name()<<endl;
    return 0;
}
