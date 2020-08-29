/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.18
History
    version 1.0 2016.10.21
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::placeholders::_1;
using namespace std; 
int main() {
	vector<string> vs{"","a","","","d",""};
	auto cnt=count_if(vs.begin(),vs.end(),bind(&string::empty,_1));
	cout<<cnt<<endl; 
    return 0;
}
