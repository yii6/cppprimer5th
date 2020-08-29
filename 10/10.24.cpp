/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 10.24
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using namespace std::placeholders;
bool check_size(const string &s,string::size_type sz) {
    return s.size()<sz;
}
int main(int argc,char *argv[]) {
    ifstream in("10.1.txt");
    int num;
    vector<int> vi;
    while(in>>num)
        vi.push_back(num);
    string s("hello,world!");
    for(auto c:vi) {
        auto g=bind(check_size,_1,c);
        if(g(s)) {
            cout<<c;
            break;
        }
	}
    return 0;
}
