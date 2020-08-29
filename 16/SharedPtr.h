/*
Author
	whulinus 1034765650@qq.com
Program
	SharedPtr.h
History
	version 1.0
	2016.8.27
*/
#ifndef SHAREDPTR_H
#define SHAREDPTR_H
#include <functional>
#include "DebugDelete.h"
template<typename> class SharedPtr;
template<typename T> void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs);
template <typename T>
class SharedPtr{
public:
//friends
    friend void swap<T>(SharedPtr<T> &lhs, SharedPtr<T> &rhs);
//constructors
    SharedPtr() = default;
    explicit SharedPtr(T *up, std::function<void(T *)> d = DebugDelete()) :
        ptr(up), refCount(new std::size_t(1)), deleter(d) { }
//copy constructor
    SharedPtr(const SharedPtr &sp):
        ptr(sp.ptr), refCount(sp.refCount), deleter(sp.deleter) {
        ++*refCount;
    }
//move constructor
    SharedPtr(SharedPtr &&sp) noexcept;
//copy-assignment operator
    SharedPtr &operator =(const SharedPtr &rhs);
//move-assignment operator
    SharedPtr &operator =(SharedPtr &&rhs) noexcept;
//destructor
    ~SharedPtr() {
        decrement_n_destroy();
    }
//overloaded operator
    operator bool() const {
        return ptr ? true : false;
    }
    T &operator* () const {
        return *ptr;
    }
    T *operator->() const {
        return & this->operator *(); //return address
    }
//functions
    std::size_t use_count() const {
        return *refCount;
    }
    T *get() const {
        return ptr;
    }
    bool unique() const {
        return *refCount == 1;
    }
    void swap( SharedPtr &rhs) {
        ::swap(*this, rhs);
    }
    void reset(){
        decrement_n_destroy();
    }
    void reset(T *p) {
        if(ptr != p) {
            decrement_n_destroy();
            ptr = p;
            refCount = new std::size_t(1);
        }
    }
    void reset(T *p, const std::function<void(T *)> &d) {
        reset(p);
        deleter = d;
    }
protected:
private:
    T *ptr = nullptr;
    std::size_t *refCount = new std::size_t(0);
    std::function<void(T *)> deleter{DebugDelete()};
//private functions
    void decrement_n_destroy();
};
//constructors
template<typename T>
inline
SharedPtr<T>::SharedPtr(SharedPtr &&sp) noexcept:
    ptr(sp.ptr), refCount(sp.refCount), deleter(std::move(sp.deleter)) {
    sp.ptr = nullptr;
    sp.refCount = nullptr;
}
//overloaded operator members
template<typename T>
inline SharedPtr<T> &
SharedPtr<T>::operator =(const SharedPtr &rhs) {
    ++*rhs.refCount;
    decrement_n_destroy();
    ptr = rhs.ptr;
    refCount = rhs.refCount;
    deleter  = rhs.deleter;
    return *this;
}
template<typename T>
inline SharedPtr<T> &
SharedPtr<T>::operator =(SharedPtr &&rhs) noexcept {
    decrement_n_destroy();
    ::swap(*this, rhs);
    std::cout << "SharedPtr::move=\n";
    return *this;
}
//other overloaded operator
//public functions
//private functions
template <typename T>
inline void
SharedPtr<T>::decrement_n_destroy() {
    if(ptr) {
        if (--*refCount == 0) {
            delete refCount;
            deleter(ptr);
        }
        refCount = nullptr;
        ptr = nullptr;
    }
}
//other functions
template <typename T>
inline void
swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.refCount, rhs.refCount);
    swap(lhs.deleter, rhs.deleter);
}
#endif
