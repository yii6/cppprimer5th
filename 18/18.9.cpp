/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 18.9
History
    version 1.0 2016.10.7
*/
#include <iostream>
#include <fstream>
#include "Sales_data_old.h"
using namespace std;

int main() {
	ifstream cin("salesData.txt");
	Sales_data a,b;
	cin>>a>>b;
	cout<<a+b<<endl; 
    return 0;
}
