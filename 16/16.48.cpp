/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.65
History
    version 1.0 2016.9.16
*/
#include <iostream>
#include <sstream>
using namespace std;
template <typename T>string debug_rep(const T &t){
	ostringstream ret;
	ret<<t;
	return ret.str();
} 
template <typename T>string debug_rep(T *p){
	ostringstream ret;
	ret<<"pointer:"<<p;
	if(p)
		ret<<" "<<debug_rep(*p);
	else
		ret<<"null pointer";
	return ret.str();
}
template <>string debug_rep(char *p){
	return debug_rep(string(p));
}
template <>string debug_rep(const char *p){
	return debug_rep(string(p));
}
int main() {
    return 0;
}
