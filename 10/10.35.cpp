/*
Author
    whulinus 1034765650@qq.com
Program
    use iterator to print a vector in reverse.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;
int main(int argc,char *argv[]) {
	ifstream in("10.1.txt");
    istream_iterator<int> int_ii(in),eof;
    vector<int> vi(int_ii,eof);
    for(auto beg=vi.end()-1;beg!=vi.begin()-1;--beg)
    	cout<<*beg<<" ";
    return 0;
}
