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
    try {
        regex r("[[:alnum]+\\.(cpp|cc)$",regex::icase);
    }
    catch(regex_error e) {
        cout<<e.what()<<"\ncode:"<<e.code()<<endl;
        try {
            regex r("[[:alnum]]+\\.cpp|cc)$",regex::icase);
        }
        catch(regex_error e) {
            cout<<e.what()<<"\ncode:"<<e.code()<<endl;
            try {
                regex r("[[:alnum]+.(cpp|cc)$",regex::icase);
            }
            catch(regex_error e) {
                cout<<e.what()<<"\ncode:"<<e.code()<<endl;
            }
        }
    }
    return 0;
}
