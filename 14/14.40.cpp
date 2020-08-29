/*
Author
    whulinus 1034765650@qq.com
Program
    use function object to replace lambda expression to rewrite biggise.
History
    version 1.0
    2016.7.28
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
class ShorterString{
public:
	bool operator()(const string &s1,const string &s2)const {
	return s1.size()<s2.size();}
};
class SizeComp{
public:
	SizeComp(size_t n):sz(n){
	}
	bool operator()(const string &s)const{
		return s.size()<=sz;
	}
private:
	size_t sz;
};
class Print{
public:
	void operator()(const string &s){
		cout<<s<<" ";
	}
};
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
    stable_sort(words.begin(),words.end(),ShorterString());
    auto wc=partition(words.begin(),words.end(),SizeComp(sz));
    auto count=words.end()-wc;
    cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;
    for_each(wc,words.end(),Print());
    cout<<endl;
}

int main(int argc,char *argv[]) {
    ifstream in("essay.txt");
    string word;
    vector<string> article;
    while(in>>word)
        article.push_back(word);
    biggies(article,5);
    return 0;
}
