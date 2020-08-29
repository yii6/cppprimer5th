/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.51
History
    version 1.0 2016.9.11
*/
#include <iostream>
#include <string>
using namespace std;
template<typename T,typename...Args>void foo(const T &t,const Args&...args){
	cout<<sizeof...(Args)<<" "<<sizeof...(args)<<endl;
}
int main() {
	int i=0;
	double d=3.4;
	string s="how now brown cow";
	foo(i,s,42,d);
	foo(s,42,"hi");
	foo(d,s);
	foo("hi");
    return 0;
}
