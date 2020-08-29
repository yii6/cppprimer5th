/*  
Author
	whulinus 1034765650@qq.com
Program
	test whether two vector<int> is equal.
History
	version 1.0
	2016.6.21
*/
#include <iostream>
#include <vector>
using namespace std;

void test(vector<int> v2,vector<int> v1) {
    if(v1==v2)
        cout<<"equal."<<endl;
    else
        cout<<"unequal."<<endl;
}
int main(int argc,char *argv[]) {
    vector<int> v1{1,2,4,5},v2(v1),v3(3);
    test(v1,v2);
    test(v2,v3);
    return 0;
}
