/*  
Author
	whulinus 1034765650@qq.com
Program
	save lines from a file to a vector<string>,then use a istringstream to read elements
    from vector, a word each time.
History
	version 1.0
	2016.6.16
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in(argv[1]);
    string s;
    vector<string> vec;
    while(getline(in,s))
        vec.push_back(s);
    for(auto &c:vec) {
        istringstream record(c);
        string word;
        while(record>>word)
            cout<<word<<endl;
    }
    return 0;
}
