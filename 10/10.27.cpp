/*
Author
    whulinus 1034765650@qq.com
Program
    use unique_copy to copy elements from vector to list.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    string word;
    vector<string> article;
    while(in>>word)
        article.push_back(word);
    list<string> essay;
    sort(article.begin(),article.end());
    unique_copy(article.begin(),article.end(),back_inserter(essay));
    print(essay);
    return 0;
}
