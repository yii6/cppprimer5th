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
#include <vector>
#include <list>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    int ia[]= {0,1,2,3,5,8,13,21,55,89};
    vector<int> vec(begin(ia),end(ia));
    list<int> li(vec.begin(),vec.end());
    auto beginv=vec.begin();
    while(beginv!=vec.end())
        if(*beginv%2)
            ++beginv;
        else
            beginv=vec.erase(beginv);
    auto beginl=li.begin();
    while(beginl!=li.end())
        if(*beginl%2)
            beginl=li.erase(beginl);
        else
            ++beginl;
    print(vec);
    cout<<endl;
    print(li);
    cout<<endl;
    return 0;
}
