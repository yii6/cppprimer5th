/*  
Author
	whulinus 1034765650@qq.com
Program
	copy elements from list<int> to two deque.
History
	version 1.0
	2016.6.22
*/
#include <iostream>
#include <list>
#include <deque>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    list<int> li{1,2,3,4,5,6,8};
    deque<int> even,odd;
    auto begin=li.begin();
    while(begin!=li.end()){
    	if(*begin%2)
    	odd.push_back(*begin);
    	else
    	even.push_back(*begin);
    	++begin;
	}
	print(odd);cout<<endl;
	print(even);
    return 0;
}
