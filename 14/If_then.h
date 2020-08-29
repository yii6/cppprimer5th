/*Author
	whulinus 1034765650@qq.com
Program
	function object class
History
	version 1.0 2016.7.26
*/
#ifndef IFTHEN_H
#define IFTHEN_H
#include <iostream>
#include <string>

class If_then {
public:
//friends
//constructors
	If_then(int v) : value(v){}
//overloaded assignment operator
    std::string &operator()(int,std::string &,std::string &);
    bool operator()(int);
    bool operator()(const std::string&);
//functions
private:
	int value;
//private functions
};
//constructors
//overloaded assignment operator
std::string &If_then::operator()(int n,std::string &succeed,std::string &fail) {
    return n>0?succeed:fail;
}
bool If_then::operator()(int tmp){
	return value==tmp;
}
bool If_then::operator()(const std::string &s){
	return s.size()==value;
}

//functions
//private functions
#endif

