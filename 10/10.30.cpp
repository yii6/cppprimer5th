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
    istream_iterator<int> int_it(in), eof;
    vector<int> vi;
    copy(int_it,eof,back_inserter(vi));
    sort(vi.begin(),vi.end());
    ostream_iterator<int> int_ot(cout," ");
    for(auto c:vi)
        *int_ot++=c;
    cout<<endl;
    return 0;
}
