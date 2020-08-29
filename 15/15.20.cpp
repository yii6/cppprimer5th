/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 15.20
History
    version 1.0
    2016.8.4
*/
#include <iostream>
using namespace std;
class Base {
public:
    void pub_mem();
    void memfcn(Base &b) {
        b=*this;
    }
protected:
    int prot_mem;
private:
    char priv_mem;
};
struct Pub_derv:public Base {
    int f() {
        return prot_mem;
    }
    void memfcn(Base &b) {
        b=*this;
    }
    //char g(){return priv_mem}
};
struct Priv_derv:private Base {
    int f1() const {
        return prot_mem;
    }
    void memfcn(Base &b) {
        b=*this;
    }
};
struct Prot_derv:protected Base {
    int f2() {
        return prot_mem;
    }
    void memfcn(Base &b) {
        b=*this;
    }
};
struct Derived_from_public :public Pub_derv {
    int use_base() {
        return prot_mem;
    }
    void memfcn(Base &b) {
        b=*this;
    }
};
struct Derived_from_private :public Priv_derv {
   /*  int use_base() {
        return prot_mem;
    }
   
   void memfcn(Base &b) {
        b=*this;
    }
    //*/
};
struct Derived_from_protected :public Prot_derv {
    int use_base() {
        return prot_mem;
    }
    void memfcn(Base &b) {
        b=*this;
    }
};
int main(int argc,char *argv[]) {
    Pub_derv d1;
    Priv_derv d2;
    Prot_derv d3;
    Derived_from_public dd1;
    Derived_from_private dd2;
    Derived_from_protected dd3;
    Base *p=&d1;
   // p=&d2;
   // p=&d3;
   // p=&dd2;
    p=&dd1;
    //p=&dd3;
    return 0;
}
