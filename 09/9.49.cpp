/*
Author
	whulinus 1034765650@qq.com
Program
	read a word file, print the longest word which has no ascenders or descenders.
History
	version 1.0
	2016.6.28
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("9.49.txt");
    string word,adscender("bdfghijklpqtyABCDEFGHIJKLMNOPQRSTUVWXYZ"),maxword;
    while(in>>word)
        if(word.find_first_of(adscender)==string::npos&&word.size()>maxword.size()) 
            maxword=word;
    cout<<maxword<<endl;
    return 0;
}
