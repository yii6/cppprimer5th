/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.4
History
    version 1.0 2016.9.18
*/
#include <iostream> 
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Sales_data.h"
using namespace std;
typedef tuple<vector<Sales_data>::size_type,vector<Sales_data>::const_iterator,vector<Sales_data>::const_iterator> matches;
vector<matches> findBook(const vector<vector<Sales_data>> &files,const string& book){
	vector<matches> ret;
	for(auto it=files.cbegin();it!=files.cend();++it){
		auto found=equal_range(it->cbegin(),it->cend(),book);
		if(found.first!=found.second)
			ret.push_back(make_tuple(it-files.cbegin(),found.first,found.second));
	}
	return ret;
}

void reportResults(istream &in,ostream &os,const vector<vector<Sales_data>> &files){
	string s;
	while(in>>s){
		auto trans=findBook(files,s);
		if(trans.empty()){
			cout<<s<<" not found in any stores"<<endl;
			continue;
		}
		for(const auto &store:trans)
			os<<"store "<<get<0>(store)<<" sales: "<<accumulate(get<1>(store),get<2>(store),Sales_data(s))<<endl; 
	} 	
}
int main() {
	
    return 0;
}
