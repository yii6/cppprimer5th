/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.16
History
    version 1.0
    2016.7.4
*/
#include <iostream>
#include <map>
using namespace std;

int main(int argc,char *argv[]) {
    map<int,int> m{{1,2}};
    m.begin()->second=4;
    cout<<m[1];
    return 0;
}
