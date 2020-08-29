/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.19
History
    version 1.0 2016.10.21
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include "Sales_data.h"
using std::placeholders::_1;
using namespace std; 
#define avg_value 25
bool bigger(Sales_data &s){
	if(s.avg_price()>avg_value)
		return true;
	else
		return false;
}
int main() {
	ifstream cin("Sales_data.txt");
	vector<Sales_data> vs;
	Sales_data s;
	while(cin>>s)
		vs.push_back(s);
	auto cnt=find_if(vs.begin(),vs.end(),bigger);
	cout<<*cnt<<endl; 
    return 0;
}
