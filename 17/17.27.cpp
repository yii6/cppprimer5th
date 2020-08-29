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
using namespace std::regex_constants;
int main() {
    string p ="(\\d{5})(-)?(\\d{4})";
    regex r(p) ;
    smatch m;
    string s;
    string fmt="$1-$3";
    ifstream cin("postalCode.txt");
    while(getline(cin,s)) 
        cout<<regex_replace(s,r,fmt)<<endl;
    return 0;
}
