/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.4
History
    version 1.0 2016.9.18
*/
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"
using namespace std;
struct matchs{
	vector<Sales_data>::size_type st;
	vector<Sales_data>::const_iterator cb;
	vector<Sales_data>::const_iterator ce;
};

matchs findBooks(const vector<vector<Sales_data>> &files,const string& book){
	matchs ret;
	for(auto it=files.cbegin();it!=files.cend();++it){
		auto found=equal_range(it->cbegin(),it->cend(),book);
		if(found.first!=found.second){
			ret.st=it-files.cbegin();
			ret.cb=found.first;
			ret.ce=found.second;
		}
	}
	return ret;
}
void reportResults(istream &in,ostream &os,const vector<vector<Sales_data>> &files){
	string s;
	while(in>>s){
		auto trans=findBooks(files,s);
		if(trans.st==0){
			cout<<s<<" not found in any stores"<<endl;
			continue;
		}
		os<<"store "<<trans.st<<" sales: "<<accumulate(trans.cb,trans.ce,Sales_data(s))<<endl; 
	} 	
}
int main() {
    return 0;
}
