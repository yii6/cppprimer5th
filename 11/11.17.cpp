/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.16
History
    version 1.0
    2016.7.4
*/
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int main(int argc,char *argv[]) {
    multiset<string> c{"wo"}; 
    vector<string> v{"ca"};
    copy(v.begin(),v.end(),inserter(c,c.end()));
    //copy(v.begin(),v.end(),back_inserter(c));
    copy(c.begin(),c.end(),inserter(v,v.end()));
    copy(c.begin(),c.end(),back_inserter(v));
    return 0;
}
