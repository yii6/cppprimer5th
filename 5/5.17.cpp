/*Author
	whulinus 1034765650@qq.com
Program
	check whether one vector object is another's prefix.
History
	version 1.0
	2016.5.11
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> seq1{0,1,1,2},seq2{0,1,1,2,3,4,5};
    bool flag=true;
    auto length=seq1.size()<seq2.size()?seq1.size():seq2.size();
    decltype(seq1.size()) i;
    for(i=0; i<length; ++i) 
        if(seq1[i]!=seq2[i]) {
            flag=false;
            break;
        }
    if(flag&&length==i)
        cout<<"true."<<endl;
    else
        cout<<"false."<<endl;
    return 0;
}
