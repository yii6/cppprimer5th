/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	HasPtr.h
 *History
 *	ver 1.0 2016.7.14
 *	ver 2.0 2016.7.22
 *	add move-assignment operator
 */
#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <iostream>
class HasPtr {
public:
    std::string *ps;
    int i;
//destructor
    ~HasPtr() {}
//constructor
	HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0){}
//copy constructor
	HasPtr(const HasPtr &hp):i(hp.i),ps(new std::string(*hp.ps)) {}
//copy-assignment operator
    HasPtr &operator=(HasPtr);
    bool operator<(const HasPtr&)const;
//move-assignment operator
	HasPtr &operator=(HasPtr&&);
//friends
    friend void swap(HasPtr&,HasPtr&);
};
HasPtr& HasPtr::operator=(HasPtr r) {
    swap(*this,r);
    return *this;
}
HasPtr& HasPtr::operator=(HasPtr &&r){
	if(&r!=this){
		delete ps;
		i=std::move(r.i);
		ps=r.ps;
		r.ps=nullptr;
	}
	return *this;
}
bool HasPtr::operator<(const HasPtr &rl)const{
	return *ps<*rl.ps;
}
void swap(HasPtr &lhs,HasPtr &rhs){
	using std::swap;
	swap(lhs.ps,rhs.ps);
	swap(lhs.i,rhs.i);
	std::cout<<"swap now."<<std::endl;
}
#endif
