/*
Author
    whulinus 1034765650@qq.com
Program
    use reverse_iterator to print a vector.
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
    for(auto rbeg=vi.rbegin();rbeg!=vi.rend();++rbeg)
    	cout<<*rbeg<<" ";
    return 0;
}
