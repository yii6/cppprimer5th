/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.61
History
    version 1.0 2016.9.16
*/
#include <iostream>
#include <vector>
#include <string> 
#include <algorithm> 
using namespace std;
template <typename T>int count_times(vector<T> &vt,T t){
	return count(vt.begin(),vt.end(),t);
}
template <> int count_times(vector<const char*> &vc,const char *t){
	int ct=0;
	for(auto &c:vc)
		if(*c==*t)
			++ct;
	return ct;
}
int main() {
	vector<string> vs{"a","bb","a"};
	vector<int> vi{1,2,3,2};
	vector<double> vd{1.2,1.3,1.2};
	vector<const char*> vc{"a","bb","a"};
	string s("a");
	const char *p="a";
	int i=2;
	double d=1.2;
	cout<<count_times(vs,s)<<endl;
	cout<<count_times(vc,p)<<endl;
	cout<<count_times(vc,"bb")<<endl;
	cout<<count_times(vi,i)<<endl;
	cout<<count_times(vd,d)<<endl;
    return 0;
}
