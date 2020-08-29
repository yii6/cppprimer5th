/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.11
History
    version 1.0
    2016.7.4
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("11.12.txt");
    string s;
    int i;
    vector<pair<string,int>> vpm,vpp,vpl;
    while(in>>s>>i){
    	vpm.push_back(make_pair(s,i));
    	vpp.push_back(pair<string,int>(s,i));
    	vpl.push_back({s,i});
	}
    for(auto &c:vpm)
	cout<<c.first<<" "<<c.second<<endl;
    return 0;
}
