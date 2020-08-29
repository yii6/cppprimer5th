/*
Author
	whulinus 1034765650@qq.com
Program
	debugDelete.h
History
	version 1.0
	2016.8.22
*/
#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H
#include <iostream>
class DebugDelete {
public:
//friends
//constructors
    DebugDelete(std::ostream &s=std::cerr):os(s) {
    }
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded operator
    template <typename T>void operator()(T *p)const {
        os<<"deleting..."<<std::endl;
        delete p;
    }
//functions
protected:
private:
    std::ostream &os;
//private functions
};
//constructors
//overloaded operator members
//other overloaded operator
//public functions
//private functions
//other functions
#endif
