/*
Author
    whulinus 1034765650@qq.com
Program
    use count in header algorithm
History
    version 1.0
    2016.6.30
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    string num;
    list<string> vi;
    while(in>>num)
        vi.push_back(num);
    cout<<count(vi.begin(),vi.end(),"a");
    return 0;
}
