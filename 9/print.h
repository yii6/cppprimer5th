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
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <forward_list>
inline void swap(int &a,int &b) {
	int c=a;
	a=b;
	b=c;
}
inline void swap(int *a,int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
inline void swapp(int *(&p),int *(&q)){
	int *tmp=p;
	p=q;
	q=tmp;
}
inline void print(int a,int b) {
    if(a<b)
        swap(a,b);
    while(--a>b)
        std::cout<<a<<std::endl;
}
inline void print(std::vector<std::string> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(std::forward_list<std::string> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(std::vector<int> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(std::deque<int> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(std::list<int> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(std::forward_list<int> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(std::vector<double> &vec) {
    for(auto i:vec)
        std::cout<<i<<" ";
}
inline void print(const int *cp) {
    if(cp)
        std::cout<<*cp<<std::endl;
}
inline void print(const int (&cp)[2]) {
    for(auto c:cp)
        std::cout<<c;
    std::cout<<std::endl;
}
inline void print (const int *beg,const int *end) {
    while(beg!=end) {
        std::cout<<*beg;
        ++beg;
    }
    std::cout<<std::endl;
}
inline void print(const int ia[],size_t size) {
    for(size_t i=0; i!=size; ++i)
        std::cout<<ia[i];
    std::cout<<std::endl;
}
#endif
