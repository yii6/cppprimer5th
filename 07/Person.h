/*Author
	whulinus 1034765650@qq.com
Program
	header with constructor.
History
	version 1.0  
	2016.5.22
	version 2.0 
	add some constructor
	2016.5.28
	version 3.0
	access specifiers and friend
	2016.5.30
*/
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
struct Person;
std::istream &read(std::istream &is,Person &data);
struct Person {
	friend std::ostream &print(std::ostream &,const Person &);
    friend std::istream &read(std::istream &,Person &);
	std::string whatName() const {return name;}
    std::string whatAddress() const {return address;}
    Person()=default;
    Person(const std::string &s1,const std::string &s2):name(s1),address(s2){}
    explicit Person(std::istream &is){read(is,*this);}
    private:
	std::string name;
    std::string address;
};
std::istream &read(std::istream &is,Person &data) {
    is>>data.name>>data.address;
    return is;
}
std::ostream &print(std::ostream &os,const Person &data) {
    os<<data.name<<" "<<data.address;
    return os;
}
#endif

