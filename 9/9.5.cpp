/* 
Author
	whulinus 1034765650@qq.com
Program
	exercise 9.5
History
	version 1.0
	2016.6.18
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator find(vector<int>::iterator begin,vector<int>::iterator end,int i) {
    while(begin != end)
        if(*begin==i)
            return begin;
        else
            ++begin;
    cout<<"no match"<<endl;
    return end;
}
int main(int argc,char *argv[]) {
    vector<int> vec{1,2,3,4,5};
    cout<<find(vec.begin(),vec.end(),6)-vec.begin()<<endl;
    return 0;
}
