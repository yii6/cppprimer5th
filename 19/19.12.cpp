/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.12
History
    version 1.0 2016.10.19
*/
#include <iostream>
#include "Screen.h"
using namespace std; 
int main() {
	auto Screen::*p=Screen::cur();
	Screen m;
	auto s=m.*p;
	cout<<s<<endl;
    return 0;
}
