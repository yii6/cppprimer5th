/*
Author
    whulinus 1034765650@qq.com
Program
    use accumulate in header numeric
History
    version 1.0
    2016.6.30
*/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
    vector<int> vec{1,23,4,5,6};
    cout<<accumulate(vec.cbegin(),vec.cend(),0)<<endl;
    vector<double> vd{1.2,23,4,5,6};
    cout<<accumulate(vd.cbegin(),vd.cend(),0.0);
    return 0;
}
