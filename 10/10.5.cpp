/*
Author
    whulinus 1034765650@qq.com
Program
    compare two c-style string.
History
    version 1.0
    2016.6.30
*/
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main(int argc,char *argv[]) {
	char c2[]={'c','+','+'},c1[]="c==";
	vector<char*> roster1{c1,c2};
	list<char*> roster2{c1,c2};
    list<string> s{"c==","c++"};
    cout<<equal(roster1.cbegin(),roster1.cend(),roster2.cbegin());
    cout<<equal(roster1.cbegin(),roster1.cend(),s.cbegin());
    return 0;
}
