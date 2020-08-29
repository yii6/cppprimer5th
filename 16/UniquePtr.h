/*
Author
	whulinus 1034765650@qq.com
Program
	UniquePtr.h
History
	version 1.0
	2016.8.28
*/
#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H
#include "DebugDelete.h"
template<typename,typename> class UniquePtr;
template<typename T,typename D> void swap(UniquePtr<T,D> &lhs,
                                          UniquePtr<T,D> &rhs);
template <typename T,typename D=DebugDelete>
class UniquePtr {
public:
//friends
    friend void swap<T,D>(UniquePtr<T,D> &lhs, UniquePtr<T,D> &rhs);
//constructors
    UniquePtr() = default;
    explicit UniquePtr(T *up) :ptr(up) { }
//copy constructor
    UniquePtr(const UniquePtr &)=delete;
//move constructor
    UniquePtr(UniquePtr &&) noexcept;
//copy-assignment operator
    UniquePtr &operator =(const UniquePtr &)=delete;
//move-assignment operator
    UniquePtr &operator =(UniquePtr &&) noexcept;
//nullptr_t assignment
    UniquePtr &operator =(std::nullptr_t) noexcept;
//destructor
    ~UniquePtr() {
        deleter(ptr);
    }
//overloaded operator
    operator bool() const {
        return ptr ? true : false;
    }
    T &operator* () const {
        return *ptr;
    }
    T *operator->() const {
        return & this->operator *();
    }
//functions
    T *get() const {
        return ptr;
    }
    void swap(UniquePtr &rhs) {
        ::swap(*this, rhs);
    }
    void reset() {
        deleter(ptr);
        ptr=nullptr;
    }
    void reset(T *p) {
        deleter(ptr);
        ptr = p;
    }
    T *release();
protected:
private:
    T *ptr = nullptr;
    D deleter=D();
//private functions
};
//constructors
template<typename T,typename D>
inline
UniquePtr<T,D>::UniquePtr(UniquePtr &&sp) noexcept:ptr(sp.ptr) {
    sp.ptr = nullptr;
}
//overloaded operator members
template<typename T,typename D>
inline UniquePtr<T,D> &
UniquePtr<T,D>::operator=(UniquePtr &&rhs) noexcept {
    if(this->ptr!=rhs.ptr) {
        deleter(ptr);
        ptr = nullptr;
        ::swap(*this,rhs);
    }
    return *this;
}
template<typename T,typename D>
inline UniquePtr<T,D> &
UniquePtr<T,D>::operator=(std::nullptr_t rhs) noexcept {
    if(rhs==nullptr) {
        deleter(ptr);
        ptr = nullptr;
    }
    return *this;
}
//other overloaded operator
//public functions
template<typename T,typename D>
inline T*
UniquePtr<T,D>::release() {
    T *ret=ptr;
    ptr = nullptr;
    return ret;
}
//private functions
//other functions
template <typename T,typename D>
inline void
swap(UniquePtr<T,D> &lhs, UniquePtr<T,D> &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}
#endif
