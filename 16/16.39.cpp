/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.39
History
    version 1.0 2016.9.3 
*/
#include <iostream>
#include <string>
using namespace std;
template<typename T>int compare(const T& v1,const T& v2){
	if(v1<v2)return -1;
	if(v2<v1)return 1;
	return 0;
}
int main(int argc,char *argv[]) {
	cout<<compare<string>("HI","WORs")<<endl;
    return 0;
}
