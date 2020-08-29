/*
Author
    whulinus 1034765650@qq.com
Program
    allow user to offer a seed as an argument option 
History
    version 1.0 2016.9.30
*/
#include <iostream>
#include <random>
using namespace std;
unsigned int randI(int s,int min,int max){
	static default_random_engine e(s);
	uniform_int_distribution<unsigned> u(min,max);
    return u(e);
} 
int main() {
    for(int i=0;i<100;i+=10)
    cout<<randI(i,i,i+10)<<" ";
    return 0;
}
