/*
Author
    whulinus 1034765650@qq.com
Program
    use stream iterator to read a text file, save it to a vector<string>.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.2.txt");
	istream_iterator<string> str_it(in);
	istream_iterator<string> eof;
	vector<string> vs(str_it,eof);
	print(vs); 
    return 0;
}
