/*  
Author
	whulinus 1034765650@qq.com
Program
	delete even numbers and copy odd numbers, apply it to list and forward_list
History
	version 1.0
	2016.6.25
*/
#include <iostream>
#include <forward_list>
#include <list>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    list<int> li={0,1,2,3,4,5,6,7,8,9};
    forward_list<int> fl(li.begin(),li.end());
    auto iter=li.begin();
    while(iter!=li.end())
        if(*iter&0x1) {
            li.insert(iter,*iter);
            ++iter;
        }
        else
            iter=li.erase(iter);
    auto curr=fl.begin();
    auto pre=fl.before_begin();
    while(curr!=fl.end())
        if(*curr&0x1) {
            curr=fl.insert_after(curr,*curr);
            pre=curr;
            ++curr;
        }
        else
            curr=fl.erase_after(pre);
    print(li);
    cout<<endl;
    print(fl);
    return 0;
}
