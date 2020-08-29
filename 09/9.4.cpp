/*  
Author
	whulinus 1034765650@qq.com
Program
	iterator
History
	version 1.0
	2016.6.18
*/
#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int>::iterator begin,vector<int>::iterator end,int i) {
    while(begin != end)
        if(*begin==i)
            return true;
        else
            ++begin;
    return false;
}
int main(int argc,char *argv[]) {
    vector<int> vec{1,2,3,4,5};
    cout<<find(vec.begin(),vec.end(),4)<<endl;
    return 0;
}
