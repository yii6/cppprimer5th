/*
Author
    whulinus 1034765650@qq.com
Program
    words counting program.
History
    version 1.0
    2016.7.3
*/
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <fstream>
using namespace std;
string make_plural(size_t ctr,const string &word,const string &ending) {
    return (ctr>1)?word+ending:word;
}
int main(int argc,char *argv[]) {
    ifstream in("essay.txt");
    string word;
    map<string,size_t> article;
    set<string> exclude{"the","but","and","or","an","a","The"};
    while(in>>word)
        if(exclude.find(word)==exclude.end())
        	++article[word];
    for(auto &c:article)
    	cout<<c.first<<" occurs "<<c.second<<make_plural(c.second," time","s")<<endl;
    return 0;
}
