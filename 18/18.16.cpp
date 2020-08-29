/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 18.16
History
    version 1.0 2016.10.9
*/
#include <iostream>
namespace Exercise{
	int ival=0;
	double dval=0;
	const int limit=1000;
}
int ival=0;

void manip(){
	using Exercise::ival;
//	using Exercise::dval;
using Exercise::limit;
	double dval=3.13;
	int iobj=limit+1;
	++ival;
	++::ival;
}
int main() {
	
    return 0;
}
