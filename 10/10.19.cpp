/*
Author
    whulinus 1034765650@qq.com
Program
    use stable_partition to replace find_if to rewrite biggise.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
string make_plural(size_t ctr,const string &word,const string &ending) {
    return (ctr>1)?word+ending:word;
}
void elimDups(vector<string> &words) {
    sort(words.begin(),words.end());
    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
void biggies(vector<string> &words,vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b) {return a.size()<b.size();});
    auto wc=stable_partition(words.begin(),words.end(),[sz](const string &a) {return a.size()<sz;});
    auto count=words.end()-wc;
    cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;
    for_each(wc,words.end(),[](const string &s) {cout<<s<<" ";});
    cout<<endl;
}

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    string word;
    vector<string> article;
    while(in>>word)
        article.push_back(word);
    biggies(article,5);
    return 0;
}
