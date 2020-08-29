/*  
Author
	whulinus 1034765650@qq.com
Program
	compare the elements in vector<int> and list<int>.
History
	version 1.0
	2016.6.21
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void test(vector<int> vec, list<int> li) {
    if(vec.size()==li.size()) {
        auto begin=li.begin(),end=li.end();
        auto vb=vec.begin();
        while(begin!=end)
            if(*begin==*vb) {
                ++begin;
                ++vb;
            }
            else {
                cout<<"unequal."<<endl;
                break;
            }
        if(begin==end&&*(--begin)==*(--vb))
            cout<<"equal."<<endl;
    }
    else
        cout<<"unequal."<<endl;
}
int main(int argc,char *argv[]) {
    vector<int> v1{1,2,4},v2(4);
    list<int> l1(4);
    test(v1,l1);
    test(v2,l1);
    return 0;
}
/*more easier way is to convert list<int> to vector<int>*/
