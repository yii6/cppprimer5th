/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.17
History
    version 1.0 2016.9.22
*/
#include <iostream>
#include <regex>
using namespace std;
int main() {
	string p="[[:alpha:]]*[^c]ei[[:alpha:]]*";
	regex r(p,regex::grep);
	string text="receipt freind theif cei rceiveee";
	for(sregex_iterator it(text.begin(),text.end(),r),end_it;it!=end_it;++it)
		cout<<it->str()<<endl;
    return 0;
}
