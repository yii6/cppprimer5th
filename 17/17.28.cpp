/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.28
History
    version 1.0 2016.9.30
*/
#include <iostream>
#include <random>
#include <ctime> 
using namespace std;
unsigned int randI(){
	static default_random_engine e(time(0));
	static uniform_int_distribution<unsigned> u(0,9);
    return u(e);
} 
int main() {
    for(int i=0;i<10;++i)
    cout<<randI()<<" ";
    return 0;
}
