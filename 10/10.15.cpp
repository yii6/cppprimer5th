/*
Author
    whulinus 1034765650@qq.com
Program
    write a lambda, accept one int, capture the int of the function it is in, return the sum of them
History
    version 1.0
    2016.7.1
*/
#include <iostream>
using namespace std;
void add(int b){
	auto f=[b](int a){
		return a+b;
	};
	cout<<f(3);
}

int main(int argc,char *argv[]) {
    add(1);
    return 0;
}
