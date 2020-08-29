/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.51
History
    version 1.0 2016.9.13
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template<typename T>ostream& print(ostream &os,const T &t){
	return os<<t;
} 
template<typename T,typename ... Args>ostream& print(ostream& os,const T &t,const Args& ... rest){
	os<<t<<",";
	return print(os,rest...);
}
template <typename T>string debug_rep(const T &t){
	ostringstream ret;
	ret<<t;
	return ret.str();
}
template <typename ...Args>ostream &errorMsg(ostream &os,const Args&...rest){
	return print(os,debug_rep(rest)...);
} 
int main() {
	string s("aa");
	errorMsg(cerr,"other",'c',s);
    return 0;
}
