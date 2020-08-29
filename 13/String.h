/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	String.h
 *History
 *	ver 1.0 2016.7.19
 *	ver 2.0 2016.7.21
 *	add move()
 *	ver 3.0 2016.7.24
 *	add operator<
 */
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <memory>
#include <cstring>
#include <algorithm>
class String{
//friends
	friend std::ostream& operator<<(std::ostream&,const String&);
	friend bool operator==(const String&,const String&);
	friend bool operator!=(const String&,const String&);
	friend bool operator<(const String&,const String&);
public:
//constructor
	String():elements(nullptr),first_free(nullptr),cap(nullptr){}
	String(char *c){
		auto n=strlen(c);
		auto p=alloc.allocate(n);
		first_free=cap=std::uninitialized_copy_n(c,n,p);
		elements=p;
	}
//copy constructor
	String(const String &); 
//move constrctor
	String(String &&)noexcept;
//copy-assignment operator
    String &operator=(const String&);
//move-assignment operator
	String &operator=(String &&)noexcept;
//destructor
    ~String();
//other operator
	char &operator[](std::size_t n){return elements[n]; 
	}
	const char &operator[](std::size_t n)const{return elements[n]; 
	}
//functions
	size_t size()const{return first_free-elements;}
	size_t capacity() const{return cap-elements;}
	char *begin()const{return elements;}
	char *end()const{return first_free;}
	char& at(size_t pos) { return *(elements + pos); }
    const char& at(size_t pos) const { return *(elements + pos); }
private:
	static std::allocator<char> alloc;
	void chk_n_alloc(){if(size()==capacity()) reallocate();}
	std::pair<char*,char*> alloc_n_copy(const char*,const char*);
	void free();
	void reallocate();
	char *elements;
	char *first_free;
	char *cap;
//private funcs
};
bool operator==(const String &lhs,const String &rhs){
	return (lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const String &lhs,const String &rhs){
	return !(rhs==lhs);
}
bool operator<(const String &lhs,const String &rhs){
	auto n=lhs.size()<rhs.size()?lhs.size():rhs.size();
	for(decltype(n) i=0;i<n;++i)
		if(lhs.at(i)>rhs.at(i))
			return false;
		else if(lhs.at(i)<rhs.at(i))
			return true;
	return lhs.size()<rhs.size();
}
//static members
std::allocator<char> String::alloc;
//copy control members
String::String(const String &s){
	auto newdata=alloc_n_copy(s.begin(),s.end());
	elements=newdata.first;
	first_free=cap=newdata.second;
}
String::String(String &&s)noexcept:elements(s.elements),first_free(s.first_free),cap(s.cap){
	s.elements=s.first_free=s.cap=nullptr;
}
String& String::operator=(const String &rhs){
	auto data=alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements=data.first;
	first_free=cap=data.second;
	return *this;
}
String& String::operator=(String &&rhs)noexcept{
	if(this!=&rhs){
		free();
		elements=rhs.elements;
		first_free=rhs.first_free;
		cap=rhs.cap;
		rhs.elements=rhs.first_free=rhs.cap=nullptr;
	}
	return *this;
}
String::~String() {
	free();
}

//functions of String
std::pair<char*,char*> String::alloc_n_copy(const char *b,const char *e){
	auto data=alloc.allocate(e-b);
	return {data,std::uninitialized_copy(b,e,data)};
}
void String::free(){
	if(elements){
		std::for_each(elements,first_free,[](char &p){alloc.destroy(&p);});
		alloc.deallocate(elements,cap-elements);
	}
}
void String::reallocate(){
	auto newcapacity=size()?2*size():1;
	auto newdata=alloc.allocate(newcapacity);
	auto dest=newdata;
	auto elem=elements;
	for(size_t i=0;i!=size();++i)
		alloc.construct(dest++,std::move(*elem++));
	free();
	elements=newdata;
	first_free=dest;
	cap=elements+newcapacity;
}
std::ostream& operator<<(std::ostream& os,const String &s){
	for(size_t i=0;i<s.size();++i)
		os<<s.at(i);
	return os;
}
#endif
