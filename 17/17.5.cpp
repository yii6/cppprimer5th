/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.5
History
    version 1.0 2016.9.18
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Sales_data.h"
using namespace std;
typedef pair<vector<Sales_data>::size_type,pair<vector<Sales_data>::const_iterator,vector<Sales_data>::const_iterator>> matchp;

matchp findBookp(const vector<vector<Sales_data>> &files,const string& book){
	matchp ret;
	for(auto it=files.cbegin();it!=files.cend();++it){
		auto found=equal_range(it->cbegin(),it->cend(),book);
		if(found.first!=found.second){
			ret.first=it-files.cbegin();
			ret.second.first=found.first;
			ret.second.second=found.second;
		}
	}
	return ret;
}

void reportResults(istream &in,ostream &os,const vector<vector<Sales_data>> &files){
	string s;
	while(in>>s){
		auto trans=findBookp(files,s);
		if(trans.first==0){
			cout<<s<<" not found in any stores"<<endl;
			continue;
		}
			os<<"store "<<trans.first<<" sales: "<<accumulate(trans.second.first,trans.second.second,Sales_data(s))<<endl; 
	} 	
}
int main() {
	
    return 0;
}
