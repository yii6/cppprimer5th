/*  
Author
	whulinus 1034765650@qq.com
Program
	exercise 8.11
History
	version 1.0
	2016.6.17
*/
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};
int main(int argc,char *argv[]) {
    ifstream in(argv[1]);
    string line,word;
    vector<PersonInfo> people;
    istringstream record(line);
    while(getline(in,line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for(auto &pi:people){
    	cout<<pi.name<<endl;
    	for(auto &c:pi.phones)
            cout<<c<<endl;
    }
    return 0;
}
