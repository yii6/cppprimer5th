/*
Author
    whulinus 1034765650@qq.com
Program
    words counting program.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
string make_plural(size_t ctr,const string &word,const string &ending) {
    return (ctr>1)?word+ending:word;
}
int main(int argc,char *argv[]) {
    ifstream in("essay.txt");
    string word;
    map<string,size_t> article;
    while(in>>word) {
        if(ispunct(word[word.size()-1]))
            word=word.substr(0,word.size()-1);
        for(auto &c:word)
            if(isupper(c))
                c=tolower(c);
        ++article[word];
    }
    for(auto &c:article)
        cout<<c.first<<" occurs "<<c.second<<make_plural(c.second," time","s")<<endl;
    return 0;
}
