/*  
Author
	whulinus 1034765650@qq.com
Program
	use list<char *> to assign vector<string>.
History
	version 1.0
	2016.6.21
*/
#include <iostream>
#include <vector>
#include <list>
#include <string> 
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
    list<char *> li{"a","badf","dfe"};
    vector<string> vi;
    vi.assign(li.begin(),--li.end());
    print(vi);cout<<endl;
    return 0;
}
