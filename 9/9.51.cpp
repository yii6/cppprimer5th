/*
Author
	whulinus 1034765650@qq.com
Program
	calculate the sum of elements in vector<string>.
History
	version 1.0
	2016.6.28
*/
#include <iostream>
#include "date.h"
using namespace std;

int main(int argc,char *argv[]) {
    Date january("January 1,1999"),jan("Jan 22 1990"),j("3/2/1875");
    print(cout,january)<<endl; 
    print(cout,jan)<<endl; 
    print(cout,j)<<endl; 
    return 0;
}
