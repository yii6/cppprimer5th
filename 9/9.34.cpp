/*  
Author
	whulinus 1034765650@qq.com
Program
	exercise 9.34
History
	version 1.0
	2016.6.25
*/
#include <iostream>
#include <vector>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    vector<int> vi= {0,1,2,3,4,5,6,7,8,9};
    auto iter=vi.begin();
    while(iter!=vi.end()) {
        //cout<<*iter;
		if(*iter%2)
        iter=vi.insert(iter,*iter);
        ++iter;
    }
    print(vi);
    return 0;
}
