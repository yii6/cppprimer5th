/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.61
History
    version 1.0 2016.9.16
*/
#include <iostream>
#include <unordered_set>
#include <fstream>
#include "Sales_data.h"
using namespace std;

int main() {
	ifstream cin("Sales_data.txt");
	unordered_multiset<Sales_data> umS;
	Sales_data s;
	while(cin>>s)
		umS.insert(s);
	for(auto &c:umS)
	cout<<c<<endl;
    return 0;
}
