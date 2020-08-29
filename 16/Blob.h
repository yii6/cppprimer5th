/*
Author
	whulinus 1034765650@qq.com
Program
	Blob.h
History
	version 1.0  2016.8.19
	version 1.1  2016.8.19
	use SharedPtr to replace shared_ptr
*/
#ifndef BLOB_H
#define BLOB_H
#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include "SharedPtr.h"
template <typename T>class BlobPtr;
template <typename T>class Blob;
template <typename T>bool operator==(const Blob<T> &,const Blob<T> &);
template <typename T>bool operator!=(const Blob<T> &,const Blob<T> &);
template <typename T>bool operator<(const Blob<T> &,const Blob<T> &);
template <typename T>class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
//friends
    friend bool operator==<T>(const Blob<T> &,const Blob<T> &);
    friend bool operator!=<T>(const Blob<T> &,const Blob<T> &);
    friend bool operator< <T>(const Blob<T> &,const Blob<T> &);
    friend class BlobPtr<T>;
//constructors
    Blob();
    Blob(std::initializer_list<T> il);
    template<typename It>Blob(It ,It );
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded  operator
    T &operator[](size_type i);
    const T &operator[](std::size_t i)const {
    	check(i,"subscript out of range");
        return (*data)[i];
    }
//functions
    size_type size()const {
        return data->size();
    }
    bool empty()const {
        return data->empty();
    }
    void push_back(const T &t) {
        data->push_back(t);
    }
    void push_back(T &&t) {
        data->push_back(std::move(t));
    }
    void pop_back();
    T &front();
    T &back();
    const T &front()const;
    const T &back()const;
    BlobPtr<T> begin();
    BlobPtr<T> end();
protected:
private:
    SharedPtr<std::vector<T>> data;
//private functions
    void check(size_type,const std::string &)const;
};
//constructors
template <typename T>Blob<T>::Blob():data(new SharedPtr<std::vector<T>>()) {
}
template <typename T>Blob<T>::Blob(std::initializer_list<T> il):data(
        new SharedPtr<std::vector<T>>(il)) {
}
template <typename T> template<typename It>Blob<T>::Blob(It b,It e):data(new SharedPtr<std::vector<T>>(b,e)) {
}
//overloaded operator members
template <typename T>T &Blob<T>::operator[](size_type i) {
    check(i,"subscript out of range");
    return (*data)[i];
}
//other overloaded operator
template <typename T>bool operator==(const Blob<T> &lhs,const Blob<T> &rhs) {
    return *lhs.data==*rhs.data;
}
template <typename T>bool operator!=(const Blob<T> &lhs,const Blob<T> &rhs) {
    return !(rhs==lhs);
}
template <typename T>bool operator<(const Blob<T> &lhs,const Blob<T> &rhs) {
    return *lhs.data<*rhs.data;
}
//public functions
template <typename T>void Blob<T>::check(size_type i,
                                         const std::string &msg)const {
    if(i>=data->size())
        throw std::out_of_range(msg);
}
template <typename T>T &Blob<T>::back() {
    check(0,"back on empty Blob");
    return data->back();
}
template <typename T>T &Blob<T>::front() {
    check(0,"front on empty Blob");
    return data->front();
}
template <typename T>const T &Blob<T>::back()const {
    check(0,"back on empty Blob");
    return data->back();
}
template <typename T>const T &Blob<T>::front()const {
    check(0,"front on empty Blob");
    return data->front();
}
template <typename T>void Blob<T>::pop_back() {
    check(0,"pop_back on empty Blob");
    data->pop_back();
}
//private functions
//other functions
template <typename T>class BlobPtr {
public:
//friends
    friend bool operator==<T>(const BlobPtr<T> &,const BlobPtr<T> &);
    friend bool operator!=<T>(const BlobPtr<T> &,const BlobPtr<T> &);
    friend bool operator< <T>(const BlobPtr<T> &,const BlobPtr<T> &);
//constructors
    BlobPtr():curr(0) {
    }
    BlobPtr(Blob<T> &a,size_t sz=0):wptr(a.data),curr(sz) {
    }
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded operator
    T &operator*()const {
        auto p=check(curr,"dereference past end");
        return (*p)[curr];
    }
    T &operator[](std::size_t n) {
        return (*wptr.lock())[n];
    }
    const T &operator[](std::size_t n)const {
        return (*wptr.lock())[n];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    size_t operator-(const BlobPtr &);
    BlobPtr operator-(size_t);
    BlobPtr operator+(size_t);
//functions
    T &deref() const;
    BlobPtr &incr();
    std::size_t rcurr() {
        return curr;
    }
protected:
private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
//private functions
    SharedPtr<std::vector<T>>check(std::size_t ,const std::string &)const;
};
//constructors
//overloaded operator members
template <typename T>BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret=*this;
    ++*this;
    return ret;
}
template <typename T>BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(curr,"decrement past begin of StrBlobPtr");
    return *this;
}
template <typename T>BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr,"decrement past begin of StrBlobPtr");
    ++curr;
    return *this;
}
template <typename T>BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret=*this;
    --*this;
    return ret;
}
template <typename T>size_t BlobPtr<T>::operator-(const BlobPtr<T> &rhs) {
    return curr-rhs.curr;
}
template <typename T>BlobPtr<T> BlobPtr<T>::operator-(size_t n) {
    BlobPtr tmp=*this;
    tmp.curr-=n;
    return tmp;
}
template <typename T>BlobPtr<T> BlobPtr<T>::operator+(size_t n) {
    BlobPtr tmp=*this;
    tmp.curr+=n;
    return tmp;
}
//other overloaded operator
template <typename T>bool operator==(const BlobPtr<T> &lhs,
                                     const BlobPtr<T> &rhs) {
    return *lhs.wptr.lock()==*rhs.wptr.lock()&&lhs.curr==rhs.curr;
}
//public functions
template <typename T>T &BlobPtr<T>::deref() const {
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}
template <typename T>BlobPtr<T> &BlobPtr<T>::incr() {
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
//private functions
template <typename T>SharedPtr<std::vector<T>> BlobPtr<T>::check(
std::size_t i,const std::string &msg) const {
    auto ret=wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound BlobPtr");
    if(i>=ret->size())
        throw std::out_of_range(msg);
    return ret;
}
//other functions
//Blob functions related BlobPtr
template <typename T>BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}
template <typename T>BlobPtr<T> Blob<T>::end() {
    auto ret =BlobPtr<T>(*this,data->size());
    return ret;
}
#endif
