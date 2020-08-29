/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.24
History
    version 1.0 2016.9.23
*/
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;

int main() {
    string phone ="(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone) ;
	smatch m;
	string s;
	string fmt="$2.$5.$7";
	ifstream cin("nameAndPhoneNumbers.txt");
	while(getline(cin,s))
		cout<<regex_replace(s,r,fmt)<<endl;
    return 0;
}
