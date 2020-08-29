/*
Author
    whulinus 1034765650@qq.com
Program
    use delete repeated words.
History
    version 1.0
    2016.6.30
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "print.h"
using namespace std;
void elimDups(vector<string> &words) {
    print(words);
    cout<<endl;
    sort(words.begin(),words.end());
    auto end_u=unique(words.begin(),words.end());
    print(words);
    cout<<endl;
    words.erase(end_u,words.end());
    print(words);
}

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    vector<string> vs;
    string word;
    while(in>>word)
        vs.push_back(word);
    elimDups(vs);
    return 0;
}
