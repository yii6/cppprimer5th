/*  
Author
	whulinus 1034765650@qq.com
Program
	use single iterator erase to delete elements from list and vector.
History
	version 1.0
	2016.6.23
*/
#include <iostream>
#include <forward_list>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    forward_list<int> fl{0,1,2,3,5,8,13,21,55,89};
    auto pre=fl.before_begin();
    auto curr=fl.begin();
    while(curr!=fl.end())
        if(*curr&0x1)
            curr=fl.erase_after(pre);
        else {
            pre=curr;
            ++curr;
        }
    print(fl);
    return 0;
}
