/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	HasPtr.h
 *History
 *	ver 1.0 2016.7.14
 */
#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <iostream>
class HasPtr {
    std::size_t *use;
public:
    ~HasPtr() {
        std::cout << "~HasPtr()" << std::endl;
        if(--*use==0) {
            delete use;
            delete ps;
        }
    }
    std::string *ps;
    int i;
    HasPtr(const std::string &s):ps(new std::string(s)),i(0),use(new std::size_t(1)) {}
    HasPtr(const HasPtr &hp):i(hp.i),ps(new std::string(*(hp.ps))),use(hp.use) {
        ++*use;
        std::cout<<"HasPtr(const HasPtr&)"<<std::endl;
    }
    HasPtr &operator=(const HasPtr &);
    HasPtr() {
        std::cout<<"HasPtr()"<<std::endl;
    }
};
HasPtr &HasPtr::operator=(const HasPtr &r) {
    ++*r.use;
    if(--*use==0) {
        delete use;
        delete ps;
    }
    i=r.i;
    ps=r.ps;
    use=r.use;
    std::cout << "HasPtr& operator=(const HasPtr&)" << std::endl;
    return *this;
}
#endif
