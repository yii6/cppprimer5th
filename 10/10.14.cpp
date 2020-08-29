/*
Author
    whulinus 1034765650@qq.com
Program
    write a lambda, accept two int, return the sum of them
History
    version 1.0
    2016.7.1
*/
#include <iostream>
using namespace std;

int main(int argc,char *argv[]) {
    auto add=[](int a, int b){
    	return a+b;
	};
	cout<<add(1,3);
    return 0;
}
