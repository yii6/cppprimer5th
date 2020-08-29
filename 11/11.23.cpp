/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.23
History
    version 1.0
    2016.7.5
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc,char *argv[]) {
	ifstream in("11.7.txt");
    multimap<string,vector<string>> family;
    string s;
    while(getline(in,s)) {
        istringstream record(s);
        string firstname,child;
        record>>firstname;
        while(record>>child)
        family.insert({firstname,{child}});
	}
    for(auto &f:family){
    	cout<<f.first<<" has children:";
    	for(auto &c:f.second)
    	cout<<c<<" ";
    	cout<<endl;
	}
    return 0;
}
