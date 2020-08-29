/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.3
History
    version 1.0 2016.10.14
*/
#include <typeinfo>
class A {
public:
    A()=default;
    virtual ~A() {
    }
};
class B:public virtual A {
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
class D:public B,public virtual A {
public:
    D()=default;
    virtual ~D() {
    }
};
int main() {
    A *pa=new C;
    B *pb=dynamic_cast<B *>(pa);
    B *pb1=new B;
    C *pc=dynamic_cast<C *>(pb1);
    A *pa1=new D;
    B *pb2=dynamic_cast<B *>(pa1);
    try{
    	C &pc1=dynamic_cast<C&>(*pa);
	}catch(std::bad_cast){	
	}
    return 0;
}
