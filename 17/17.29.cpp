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
unsigned int randI(int s){
	static default_random_engine e(s);
	static uniform_int_distribution<unsigned> u(0,9);
    return u(e);
} 
int main() {
    for(int i=0;i<10;++i)
    cout<<randI(i)<<" ";
    return 0;
}
