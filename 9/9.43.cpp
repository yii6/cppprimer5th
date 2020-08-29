/*  
Author
	whulinus 1034765650@qq.com
Program
	write a function that accepts 3 arguments. use iterator and insert, erase function to replace oldval 
in s to newval. 
History
	version 1.0
	2016.6.27
*/
#include <iostream>
#include <string> 
#include <fstream>
using namespace std;
void replaceAbbr(string &s,const string &oldVal,const string &newVal){
	auto begin=s.begin();
	auto oldn=oldVal.end()-oldVal.begin(),newn=newVal.end()-newVal.begin();
	while(s.end()-begin>=oldVal.size())
		if(string{begin,begin+oldVal.size()}==oldVal){
			auto i=begin-s.begin();
			begin=s.erase(begin,begin+oldn);
			s.insert(begin,newVal.begin(),newVal.end());
			begin=s.begin()+i+newVal.size();
		}
		else
			++begin;
}
int main(int argc,char *argv[]) {
    ifstream in("9.43.txt");
    //ofstream out("2.txt",ofstream::app);
    string s,oldVal,newVal;
	while(getline(in,s)){
		in>>oldVal>>newVal;
		replaceAbbr(s,oldVal,newVal);
		cout<<s<<endl;
	} 
    return 0;
}
