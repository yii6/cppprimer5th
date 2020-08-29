/*
Author
    whulinus 1034765650@qq.com
Program
    delete repeated words.
History
    version 1.0
    2016.7.3
*/
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "print.h"
using namespace std;
void elimDups(list<string> &words) {
	words.sort();
    words.unique();
    print(words);
}

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
    istream_iterator<string> str_ii(in),eof;
    list<string> ls(str_ii,eof);
    elimDups(ls);
    return 0;
}
