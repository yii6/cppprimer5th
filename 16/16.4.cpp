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
#include <list>
#include <string>
using namespace std;
template <typename iter,typename val>iter finds(const iter &b,const iter &e,const val &v){
	for(auto c=b;c!=e;++c)
		if(*c==v)
			return c;
	return e;
}
int main(int argc,char *argv[]) {
	vector<int> v{3,2,1};
	list<string> l{"ri","aa"};
	auto c=finds(v.begin(),v.end(),4);
	if(c==v.end())
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;
	auto e=finds(l.begin(),l.end(),"aa");
	if(e==l.end())
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;
    return 0;
}
