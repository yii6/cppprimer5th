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
template<typename T>ostream& print(ostream &os,const T &t){
	return os<<t;
} 
template<typename T,typename ... Args>ostream& print(ostream& os,const T &t,const Args& ... rest){
	os<<t<<",";
	return print(os,rest...);
}
int main() {
	string s("aa");
	print(cout,3)<<endl;
	print(cout,3,3.12)<<endl;
	print(cout,3,3.12,true,s,'b',"cc")<<endl;
    return 0;
}
