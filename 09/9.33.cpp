/*  
Author
	whulinus 1034765650@qq.com
Program
	exercise 9.33
History
	version 1.0
	2016.6.25
*/
#include <iostream>
#include <vector>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    vector<int> v= {0,1,2,3,4,5,6,7,8,9};
    auto begin=v.begin();
    while(begin!=v.end()) {
        ++begin;
        v.insert(begin,42);
        ++begin;
    }
    print(v);
    return 0;
}
