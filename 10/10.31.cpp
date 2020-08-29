/*
Author
    whulinus 1034765650@qq.com
Program
    use stream iterator, sort, copy to read an int sequence form iostream,
sort it, cout it.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.1.txt");
    istream_iterator<int> int_ii(in), eof;
    vector<int> vi(int_ii,eof);
    sort(vi.begin(),vi.end());
    ostream_iterator<int> int_oi(cout," ");
    unique_copy(vi.begin(),vi.end(),int_oi);
    return 0;
}
