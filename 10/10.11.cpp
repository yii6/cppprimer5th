/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 10.11
History
    version 1.0
    2016.7.1 
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "print.h"
using namespace std;
void elimDups(vector<string> &words) {
    sort(words.begin(),words.end());
    auto end_u=unique(words.begin(),words.end());
    words.erase(end_u,words.end());
}
bool isShorter(const string &s1,const string &s2){
	return s1.size()<s2.size();
}
int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    vector<string> vs;
    string word;
    while(in>>word)
        vs.push_back(word);
    elimDups(vs);
    stable_sort(vs.begin(),vs.end(),isShorter);
    print(vs);
    return 0;
}
