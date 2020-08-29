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
void replaceAbbr(string &s,const string &oldVal,const string &newVal) {
    decltype(s.size()) i=0;
    while(i<=s.size()-oldVal.size()) {
        if(s.substr(i,oldVal.size())==oldVal) {
            s.replace(i,oldVal.size(),newVal);
            i+=newVal.size();
        }
        else
            ++i;
    }
}
int main(int argc,char *argv[]) {
    ifstream in("9.43.txt");
    //ofstream out("2.txt",ofstream::app);
    string s ,oldVal,newVal;
    while(getline(in,s)) {
        in>>oldVal>>newVal;
        replaceAbbr(s,oldVal,newVal);
        cout<<s<<endl;
    }
    return 0;
}
