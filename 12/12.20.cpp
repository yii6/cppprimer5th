/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.20
 *History
 *	ver 1.0 2016.7.10
 */
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include "StrBlob.h"
using namespace::std;
int main(int argc,char* argv[]){
	ifstream in("essay.txt");
	string s;
	StrBlob sb;
	while(getline(in,s)){
		istringstream record(s);
		string word;
		while(record>>word)
			sb.push_back(word);
	}
	for(auto b=sb.begin();b.rcurr()!=sb.end().rcurr();b=b.incr())
		cout<<b.deref()<<" ";
	return 0;
}
