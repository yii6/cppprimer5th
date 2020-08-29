/*
Author
    whulinus 1034765650@qq.com
Program
    use partition
History
    version 1.0
    2016.7.1
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool longer_than5(const string &s) {
    return s.size()>=5;
}
int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    vector<string> vs;
    string s;
    while(in>>s)
    vs.push_back(s);
    auto iter=partition(vs.begin(),vs.end(),longer_than5);
    auto begin=vs.begin();
    while(begin!=iter){
    	cout<<*begin<<" ";
    	++begin;
	}
    return 0;
}
