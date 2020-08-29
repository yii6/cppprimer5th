/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.2 
History
    version 1.0
    2016.8.14
*/
#include <iostream>
#include <vector>
#include "Sales_data.h" 
using namespace std;
template <typename T>int compare(const T &a,const T &b){
	if(a<b)
		return -1;
	else if(b<a)
		return 1;
	else
		return 0;
}
int main(int argc,char *argv[]) {
	vector<int> v1{3,2,1},v2{3,1,2};
	cout<<compare(v1,v2)<<endl;
	Sales_data a("12"),b("34",2,2);
	//cout<<compare(a,b)<<endl;
    return 0;
}
