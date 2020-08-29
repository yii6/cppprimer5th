/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	Vec.h
 *History
 *	ver 1.0 2016.7.18
 *	ver 1.1 2016.7.19
 *	use for_each in free()
 *	ver 2.1 2016.7.21
 *	add move()
 *	ver 3.0 2016.7.24
 *	add operator<
 *	ver 3.1 2016.7.24
 *	add initializer_list assignment operator
 *	ver 3.2 2016.7.24
 *	add [] operator
 	ver 4.0 2016.8.21
 *	add class template
 *	ver 4.1 2016.9.13
 *	add emplace_back function
 */
#ifndef VEC_H
#define VEC_H
#include <algorithm>
#include <utility>
#include <initializer_list>
#include <iostream>
#include <memory>
template<typename T>class Vec;
template<typename T>bool operator==(const Vec<T> &,const Vec<T> &);
template<typename T>bool operator!= (const Vec<T> &,const Vec<T> &);
template<typename T>bool operator<(const Vec<T> &,const Vec<T> &);
template<typename T>bool operator>(const Vec<T> &, const Vec<T> &);
template<typename T>bool operator<=(const Vec<T> &, const Vec<T> &);
template<typename T>bool operator>=(const Vec<T> &, const Vec<T> &);
template<typename T>class Vec {
public:
//friends
    friend bool operator== <T>(const Vec<T> &,const Vec<T> &);
    friend bool operator!= <T>(const Vec<T> &,const Vec<T> &);
    friend bool operator< <T>(const Vec<T> &,const Vec<T> &);
    friend bool operator> <T>(const Vec<T> &, const Vec<T> &);
    friend bool operator<= <T>(const Vec<T> &, const Vec<T> &);
    friend bool operator>= <T>(const Vec<T> &, const Vec<T> &);
//constructor
    Vec<T>():elements(nullptr),first_free(nullptr),cap(nullptr) {}
    Vec<T>(std::initializer_list<T> il) {
        auto n=il.size();
        auto p=alloc.allocate(n);
        first_free=cap=uninitialized_copy_n(il.begin(),n,p);
        elements=p;
    }
//copy constructor
    Vec<T>(const Vec<T> &);
//move constructor
    Vec<T>(Vec<T> &&s) noexcept:elements(s.elements),first_free(s.first_free),
        cap(s.cap) {
        s.elements=s.first_free=s.cap=nullptr;
    }
//copy-assignment operator
    Vec<T> &operator=(const Vec<T> &);
    Vec<T> &operator=(std::initializer_list<T>);
//move-assignment operator
    Vec<T> &operator=(Vec<T> &&rhs)noexcept {
        if(this!=&rhs) {
            free();
            elements=rhs.elements;
            first_free=rhs.first_free;
            cap=rhs.cap;
            rhs.elements=rhs.first_free=rhs.cap=nullptr;
        }
        return *this;
    }
//destructor
    ~Vec<T>();
//other operator
    T &operator[](std::size_t n) {
        return elements[n];
    }
    const T &operator[](std::size_t n)const {
        return elements[n];
    }
//functions
    void push_back(const T &);
    size_t size()const {
        return first_free-elements;
    }
    size_t capacity() const {
        return cap-elements;
    }
    void resize(size_t n,const T &s) {
        if(n<size())
            std::for_each(elements+n,first_free,[](T &p) {
            alloc.destroy(&p);
        });
        else {
            while(n>capacity())
                reallocate();
            uninitialized_fill_n(first_free,n-size(),s);
        }
        first_free=elements+n;
    }
    void reserve(size_t n) {
        while(n>capacity())
            reallocate();
    }
    T *begin()const {
        return elements;
    }
    T *end()const {
        return first_free;
    }
    T &at(size_t pos) {
        return *(elements + pos);
    }
    const T &at(size_t pos) const {
        return *(elements + pos);
    }
    template <typename ... Args>void emplace_back(Args&&...);
private:
    static std::allocator<T> alloc;
    T *elements;
    T *first_free;
    T *cap;
//private funcs
    void chk_n_alloc() {
        if(size()==capacity()) reallocate();
    }
    std::pair<T *,T *> alloc_n_copy(const T *,
                                    const T *);
    void free();
    void reallocate();
};
//static members
template<typename T>std::allocator<T> Vec<T>::alloc;
//constructors
template<typename T>Vec<T>::Vec(const Vec<T> &s) {
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
//overloaded operator members
template<typename T>Vec<T> &Vec<T>::operator=(const Vec<T> &rhs) {
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
template<typename T>Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
    auto data=alloc_n_copy(il.begin(),il.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
template<typename T>Vec<T>::~Vec<T>() {
    free();
}
//other operator
template<typename T>bool operator==(const Vec<T> &lhs,const Vec<T> &rhs) {
    return (lhs.size() == rhs.size()
            &&std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template<typename T>bool operator!=(const Vec<T> &lhs,const Vec<T> &rhs) {
    return !(rhs==lhs);
}
template<typename T>bool operator<(const Vec<T> &lhs,const Vec<T> &rhs) {
    auto n=lhs.size()<rhs.size()?lhs.size():rhs.size();
    for(decltype(n) i=0; i<n; ++i)
        if(lhs.at(i)>rhs.at(i))
            return false;
        else if(lhs.at(i)<rhs.at(i))
            return true;
    return lhs.size()<rhs.size();
}
template<typename T>bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
    return rhs < lhs;
}

template<typename T>bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(rhs < lhs);
}

template<typename T>bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs < rhs);
}
//functions of Vec<T>
template<typename T>void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
template<typename T>std::pair<T *,T *> Vec<T>::alloc_n_copy(
    const T *b,const T *e) {
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}
template<typename T>void Vec<T>::free() {
    if(elements) {
        std::for_each(elements,first_free,[](T &p) {
            alloc.destroy(&p);
        });
        alloc.deallocate(elements,cap-elements);
    }
}
template<typename T>void Vec<T>::reallocate() {
    auto newcapacity=size()?2*size():1;
    auto newdata=alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++,move(*elem++));
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}
template<typename T>template<typename ...Args>inline void Vec<T>::emplace_back(Args&&... args){
	chk_n_alloc();
	alloc.construct(first_free++,std::forward<Args>(args)...);
}
#endif
