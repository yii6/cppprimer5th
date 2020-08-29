/*Author
	whulinus 1034765650@qq.com
Program
	input some words and change them into upper case.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<string> str;
    string word;
    while(cin>>word)
        str.push_back(word);
    for(auto &s:str)
        for(auto &c:s)
            c=toupper(c);
    for(auto s1:str)
        cout<<s1<<endl;
    return 0;
}
