/*
Author
    whulinus 1034765650@qq.com
Program
    use function to replase lambda to rewrite word counting program.
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
string make_plural(size_t ctr,const string &word,const string &ending) {
    return (ctr>1)?word+ending:word;
}
void elimDups(vector<string> &words) {
    sort(words.begin(),words.end());
    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
bool islongerthan(string &s,int l){
	return s.size()>=l;
}
void biggies(vector<string> &words,vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b) {return a.size()<b.size();});
    auto count=count_if(words.begin(),words.end(),bind(islongerthan,_1,sz));
    cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;
    for_each(words.end()-count,words.end(),[](const string &s) {cout<<s<<" ";});
    cout<<endl;
}

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    string word;
    vector<string> article;
    while(in>>word)
        article.push_back(word);
    biggies(article,6);
    return 0;
}
