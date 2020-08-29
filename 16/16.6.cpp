/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.5 
History
    version 1.0
    2016.8.15
*/
#include <iostream>
#include <string>
using namespace std;
template <typename T>T* begin(T &arr){
	return arr;
}
template <typename T>T* end(T &arr){
	return arr+arr.size();
}
int main(int argc,char *argv[]) {
	string arr[3]={"wo","ri","a"};
	auto b=begin(arr),e=end(arr);
	while(b!=e){
		cout<<*b<<" ";
		++b;
	}
	cout<<endl;
    return 0;
}
