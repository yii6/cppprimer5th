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
    string phone ="(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone) ;
    smatch m;
    string s;
    string fmt="$2.$5.$7";
    ifstream cin("nameAndPhoneNumbers.txt");
    while(getline(cin,s)) {
        auto it=sregex_iterator(s.begin(),s.end(),r),end_it=sregex_iterator();
        if(distance(it,end_it)==1)
            cout<<regex_replace(s,r,fmt)<<endl;
        else {
            cout<<it->prefix().str()<<" ";
            for(++it; it!=end_it; ++it)
                cout<<regex_replace(it->str(),r,fmt)<<" ";
            cout<<endl;
        }
    }
    return 0;
}
