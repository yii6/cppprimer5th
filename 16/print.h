/*  
Author
	whulinus 1034765650@qq.com
Program
	print integers from a to b decreasingly.
History
	version 1.0
	2016.5.19
*/
#ifndef PRINT_H
#define PRINT_H
#include <iostream>

template <typename T>inline void swap(T &a,T &b){
	auto tmp=a;
	a=b;
	b=tmp;
}
template <typename T>inline void print(T &vec){
	for(auto &i:vec)
        std::cout<<i<<" ";
}
template<typename T>void print(const T &b,const T &e){
	for(auto c=b;c!=e;++c)
		std::cout<<*c;
}
#endif
