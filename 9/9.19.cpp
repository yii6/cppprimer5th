/*  
Author
	whulinus 1034765650@qq.com
Program
	read string and save it in a list, use iterator to print deque.
History
	version 1.0
	2016.6.22
*/
#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("1.txt");
    string word;
    list<string> de;
    while(in>>word)
    	de.push_back(word);
	auto begin=de.begin();
    while(begin!=de.end()){
    	cout<<*begin;
    	++begin;
	}
    return 0;
}
