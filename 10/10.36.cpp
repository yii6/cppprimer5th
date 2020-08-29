/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 10.36 
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;
int main(int argc,char *argv[]) {
	ifstream in("10.1.txt");
    istream_iterator<int> int_ii(in),eof;
    list<int> vi(int_ii,eof);
    auto zero=find(vi.rbegin(),vi.rend(),0);
    cout<<*(zero.base())<<endl;
    return 0;
}
