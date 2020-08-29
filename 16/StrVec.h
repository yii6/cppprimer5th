/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	StrVec.h
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
 *	ver 4.0 2016.9.13
 *	add emplace_back function
 */
#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <algorithm>
#include <utility>
#include <initializer_list>
#include <iostream>
#include <memory>
class StrVec {
public:
//friends
    friend bool operator==(const StrVec &,const StrVec &);
    friend bool operator!=(const StrVec &,const StrVec &);
    friend bool operator<(const StrVec &,const StrVec &);
    friend bool operator>(const StrVec &, const StrVec &);
    friend bool operator<=(const StrVec &, const StrVec &);
    friend bool operator>=(const StrVec &, const StrVec &);
//constructor
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr) {}
    StrVec(std::initializer_list<std::string> il) {
        auto n=il.size();
        auto p=alloc.allocate(n);
        first_free=cap=uninitialized_copy_n(il.begin(),n,p);
        elements=p;
    }
//copy constructor
    StrVec(const StrVec &);
//move constructor
    StrVec(StrVec &&s) noexcept:elements(s.elements),first_free(s.first_free),
        cap(s.cap) {
        s.elements=s.first_free=s.cap=nullptr;
    }
//copy-assignment operator
    StrVec &operator=(const StrVec &);
    StrVec &operator=(std::initializer_list<std::string>);
//move-assignment operator
    StrVec &operator=(StrVec &&rhs)noexcept {
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
    ~StrVec();
//other operator
	std::string &operator[](std::size_t n){return elements[n]; 
	}
	const std::string &operator[](std::size_t n)const{return elements[n]; 
	}
//functions
    void push_back(const std::string &);
    size_t size()const {
        return first_free-elements;
    }
    size_t capacity() const {
        return cap-elements;
    }
    void resize(size_t n,const std::string &s="") {
        if(n<size())
            std::for_each(elements+n,first_free,[](std::string &p) {
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
    std::string *begin()const {
        return elements;
    }
    std::string *end()const {
        return first_free;
    }
    std::string &at(size_t pos) {
        return *(elements + pos);
    }
    const std::string &at(size_t pos) const {
        return *(elements + pos);
    }
    template <typename ...Args>void emplace_back(Args&&...);
private:
    static std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
//private funcs
    void chk_n_alloc() {
        if(size()==capacity()) reallocate();
    }
    std::pair<std::string *,std::string *> alloc_n_copy(const std::string *,
                                                        const std::string *);
    void free();
    void reallocate();
};
//static members
std::allocator<std::string> StrVec::alloc;
//copy control members
StrVec::StrVec(const StrVec &s) {
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
    auto data=alloc_n_copy(il.begin(),il.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
StrVec::~StrVec() {
    free();
}
//other operator
bool operator==(const StrVec &lhs,const StrVec &rhs) {
    return (lhs.size() == rhs.size()
            &&std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const StrVec &lhs,const StrVec &rhs) {
    return !(rhs==lhs);
}
bool operator<(const StrVec &lhs,const StrVec &rhs) {
    auto n=lhs.size()<rhs.size()?lhs.size():rhs.size();
    for(decltype(n) i=0; i<n; ++i)
        if(lhs.at(i)>rhs.at(i))
            return false;
        else if(lhs.at(i)<rhs.at(i))
            return true;
    return lhs.size()<rhs.size();
}
bool operator>(const StrVec &lhs, const StrVec &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs < rhs);
}
//functions of StrVec
void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
std::pair<std::string *,std::string *> StrVec::alloc_n_copy(
    const std::string *b,const std::string *e) {
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}
void StrVec::free() {
    if(elements) {
        std::for_each(elements,first_free,[](std::string &p) {
            alloc.destroy(&p);
        });
        alloc.deallocate(elements,cap-elements);
    }
}
void StrVec::reallocate() {
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
template<typename ...Args>inline void StrVec::emplace_back(Args&&... args){
	chk_n_alloc();
	alloc.construct(first_free++,std::forward<Args>(args)...);
}
#endif
