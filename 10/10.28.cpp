/*
Author
    whulinus 1034765650@qq.com
Program
    use back_inserter,front_inserter,inerter to copy elements from vector
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
    vector<int> num{1,2,3,4,5,6,7,8,9},vb;
    list<int> li;
    deque<int> df;
    copy(num.begin(),num.end(),back_inserter(vb));
    copy(num.begin(),num.end(),front_inserter(df));
    copy(num.begin(),num.end(),inserter(li,li.begin()));
    print(vb);cout<<endl;
    print(df);cout<<endl;
	print(li);cout<<endl;
    return 0;
}
