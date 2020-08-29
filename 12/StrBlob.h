/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	StrBlob.h
 *History
 *	ver 1.0 2016.7.7
 *	ver 2.0 2016.7.10
 *	define StrBlobPtr, add friend declaration.
 *	ver 2.1 2016.7.10
 *	add ConstStrBlobPtr
 *	ver 3.1 2016.7.22
 *	add rvalue version push_back
 *	ver 4.0 2016.7.23
 *	add operator==
 *	ver 4.1 2016.7.24
 *	add operator<
 *	ver 4.2 2016.7.26
 *	add operator* -> 
 */
#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
public:
//friends
    friend bool operator==(const StrBlob &,const StrBlob &);
    friend bool operator!=(const StrBlob &,const StrBlob &);
    friend bool operator<(const StrBlob &,const StrBlob &);
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
//constructor
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
//other operator
    std::string &operator[](std::size_t n) {
        return (*data)[n];
    }
    const std::string &operator[](std::size_t n)const {
        return (*data)[n];
    }
//functions
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const std::string &t) {
        data->push_back(t);
    }
    void push_back(std::string &&t) {
        data->push_back(move(t));
    }
    void pop_back();
    std::string &front();
    std::string &back();
    const std::string &front()const;
    const std::string &back()const;
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin()const;
    ConstStrBlobPtr cend()const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
//copy control members
StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):data(
        std::make_shared<std::vector<std::string>>(il)) {}
//other operator
bool operator==(const StrBlob &lhs,const StrBlob &rhs) {
    return *lhs.data==*rhs.data;
}
bool operator!=(const StrBlob &lhs,const StrBlob &rhs) {
    return !(rhs==lhs);
}
bool operator<(const StrBlob &lhs,const StrBlob &rhs) {
    return *lhs.data<*rhs.data;
}
//functions
std::string &StrBlob::front() {
    check(0,"front on empty StrBlob");
    return data->front();
}
std::string &StrBlob::back() {
    check(0,"back on empty StrBlob");
    return data->back();
}
const std::string &StrBlob::front()const {
    check(0,"front on empty StrBlob");
    return data->front();
}
const std::string &StrBlob::back()const {
    check(0,"back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}
void StrBlob::check (size_type i,const std::string &msg) const {
    if(i>=data->size())
        throw std::out_of_range(msg);
}
class StrBlobPtr {
public:
//friends
    friend bool operator==(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &,const StrBlobPtr &);
//constructor
    StrBlobPtr():curr(0) {}
    StrBlobPtr(StrBlob &a,std::size_t sz=0):wptr(a.data),curr(sz) {}
//other operator
    std::string &operator[](std::size_t n) {
        return (*wptr.lock())[n];
    }
    const std::string &operator[](std::size_t n)const {
        return (*wptr.lock())[n];
    }
    StrBlobPtr &operator--();
    StrBlobPtr &operator++();
    StrBlobPtr operator--(int);
    StrBlobPtr operator++(int);
    size_t operator-(const StrBlobPtr &);
    StrBlobPtr operator-(size_t);
    StrBlobPtr operator+(size_t);
    std::string &operator*()const {
    	auto p=check(curr,"derefercence past end");
        return (*p)[curr];
    }
    std::string* operator->()const {
        return & this->operator*();
    }
//functions
    std::string &deref() const;
    StrBlobPtr &incr();
    std::size_t rcurr() {
        return curr;
    }
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
//functions
    std::shared_ptr<std::vector<std::string>> check(std::size_t ,
                                                    const std::string &)const;
};
//other operators
bool operator==(const StrBlobPtr &lhs,const StrBlobPtr &rhs) {
    if(*lhs.wptr.lock()==*rhs.wptr.lock()&&lhs.curr==rhs.curr)
        return true;
    else
        return false;
}
StrBlobPtr &StrBlobPtr::operator--() {
    --curr;
    check(curr,"decrement past begin of StrBlobPtr");
    return *this;
}
StrBlobPtr &StrBlobPtr::operator++() {
    check(curr,"decrement past begin of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret=*this;
    --*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret=*this;
    ++*this;
    return ret;
}
size_t StrBlobPtr::operator-(const StrBlobPtr &rhs) {
    return curr-rhs.curr;
}
StrBlobPtr StrBlobPtr::operator-(size_t n) {
    StrBlobPtr tmp=*this;
    tmp.curr-=n;
    return tmp;
}
StrBlobPtr StrBlobPtr::operator+(size_t n) {
    StrBlobPtr tmp=*this;
    tmp.curr+=n;
    return tmp;
}
//functions
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i,
const std::string &msg) const {
    auto ret=wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i>=ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string &StrBlobPtr::deref() const {
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}
StrBlobPtr &StrBlobPtr::incr() {
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    auto ret =StrBlobPtr(*this,data->size());
    return ret;
}
class ConstStrBlobPtr {
public:
//constructor
    ConstStrBlobPtr():curr(0) {}
    ConstStrBlobPtr (const StrBlob &a,std::size_t sz=0) :wptr(a.data),curr(sz) {}
//other operators
	const std::string &operator*()const {
    	auto p=check(curr,"derefercence past end");
        return (*p)[curr];
    }
    const std::string* operator->()const {
        return & this->operator*();
    }
//functions
    std::string &deref() const;
    ConstStrBlobPtr &incr();
    std::size_t rcurr() {
        return curr;
    }
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
//functions
    std::shared_ptr<std::vector<std::string>> check(std::size_t ,
                                                    const std::string &)const;
};
std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i,
const std::string &msg) const {
    auto ret=wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if(i>=ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string &ConstStrBlobPtr::deref() const {
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}
ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr,"increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}
ConstStrBlobPtr StrBlob::cbegin()const {
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend()const {
    auto ret =ConstStrBlobPtr(*this,data->size());
    return ret;
}
class SPP {
public:
	SPP()=default;
    SPP(StrBlobPtr *ps) : p(ps) {}
    StrBlobPtr &operator*() {
        return *(this->p);
    }
    StrBlobPtr *operator->() {
        return &this->operator*();
    }
private:
    StrBlobPtr *p=nullptr;
};
#endif
