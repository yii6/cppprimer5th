/*
Author
    whulinus 1034765650@qq.com
Program
    use partition to replace find_if to rewrite biggise.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;
using namespace std::placeholders;
bool check_size(const string &s,string::size_type sz) {
    return s.size()<sz;
}
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
    auto wc=partition(words.begin(),words.end(),bind(check_size,_1,sz));
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
