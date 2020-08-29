/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.14
History
    version 1.0 2016.9.21
*/
#include <iostream>
#include <regex>
using namespace std;
int main() {
	string p("[^c]ei");
	p="[[:alpha:]]*"+p+"[[:alpha:]]*";
	regex r(p),r1("[^c]ei");
	smatch results;
	string text="receipt friend theif receive";
	if(regex_search(text,results,r))
	cout<<results.str()<<endl;
	if(regex_search(text,results,r1))
	cout<<results.str()<<endl;
    return 0;
}
