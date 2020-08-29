/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.20
History
    version 1.0 2016.9.23
*/
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;
bool valid(const smatch &m) {
    if(m[1].matched)
        return m[3].matched&&(m[4].matched==0||m[4].str()==" ");
    else
        return !m[3].matched&&m[4].str()==m[6].str();
}
int main() {
    string phone="(\\()?(\\d{3})(\\))?([-.])?\\s*(\\d{3})([-.])?\\s*(\\d{4})";
    string postalCode="(\\d{5})-?(\\d{4})?";
    regex r(phone);
    smatch m;
    string s;
    ifstream cin("17.20.txt");
    while(getline(cin,s))
        for(sregex_iterator it(s.begin(),s.end(),r),end_it; it!=end_it; ++it) 
            if(valid(*it))
                cout<<"valid: "<<it->str()<<endl;
            else
                cout<<"not valid: "<<it->str()<<endl;   
    return 0;
}
