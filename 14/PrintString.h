/*Author
	whulinus 1034765650@qq.com
Program
	function object class
History
	version 1.0 2016.7.26
*/
#ifndef PRINTSTRING_H
#define PRINTSTRING_H
#include <iostream>
#include <string>

class PrintString {
public:
//friends
//constructors
	PrintString(std::ostream &o=std::cout,char c=' '):os(o),sep(c){
	}
//overloaded assignment operator
    std::string operator()(std::istream &);
    void operator()(const std::string &s)const {os<<s<<sep;}
//functions
private:
	std::ostream &os;
	char sep;
//private functions
};
//constructors
//overloaded assignment operator
std::string PrintString::operator()(std::istream &in) {
	std::string s;
    getline(in,s);
    return s;
}
//functions
//private functions
#endif

