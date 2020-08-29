/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.19
History
    version 1.0
    2016.8.22
*/
#include <iostream>
#include <string>
using namespace std;
template<typename T>void prints(T &t){
	auto b=t.begin();
	for(typename T::size_type i=0;i<t.size();++i,++b)
		cout<<*b<<" ";
}
template<typename T>void printi(T &t){
	for(auto b=t.begin();b!=t.end();++b)
		cout<<*b<<" ";
}
int main(int argc,char *argv[]) {
	string sb("aadfef");
	prints(sb);
	cout<<endl;
	printi(sb);
    return 0;
}
