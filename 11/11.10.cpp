/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.10
History
    version 1.0
    2016.7.4
*/
#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

int main(int argc,char *argv[]) {
    map<vector<int>::iterator, int> mvi;
    map<list<int>::iterator, int> mli;
    vector<int> vi{1};
    list<int> li{2};
    mvi[vi.begin()]=1;
    //has compile error below
    //mli[li.begin()]=2;
    return 0;
}
