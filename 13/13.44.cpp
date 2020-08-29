/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	String.h
 *History
 *	ver 1.0 2016.7.19
 */
#include <iostream>
#include "String.h"
using namespace::std;
void print(const String &s) {
	for(decltype(s.size()) i=0;i<s.size();++i)
        cout<<s.at(i);
    cout<<endl;
}
int main(int argc,char* argv[]){
	char *p="aaa";
	String s1,s2(p);
	print(s1);
	print(s2);
	return 0;
}
