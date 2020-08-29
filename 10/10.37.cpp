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
#include <iterator>
#include <list>
#include <vector>
#include "print.h"
using namespace std;
int main(int argc,char *argv[]) {
	vector<int> vi{1,2,3,4,5,6,7,8,9,0};
    list<int> li(vi.rbegin()+3,vi.rend()-2);
    print(li);
    return 0;
}
