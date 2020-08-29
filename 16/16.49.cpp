/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.47
History
    version 1.0 2016.9.8
*/
#include <iostream>
#include <utility>
using namespace std;
template<typename T>void f(T t){
	cout<<"f(T)"<<endl;
} 
template<typename T>void f(const T* t){
	cout<<"f(const T*)"<<endl;
} 
template<typename T>void g(T t){
	cout<<"g(T)"<<endl;
} 
template<typename T>void g(T* t){
	cout<<"g(T*)"<<endl;
} 
int main() {
	int i=42,*p=&i;
	const int ci=0,*p2=&ci;
	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);
    return 0;
}
