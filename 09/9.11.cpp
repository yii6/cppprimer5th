/* 
Author
	whulinus 1034765650@qq.com
Program
	6 ways to initialize vector objects.
History
	version 1.0
	2016.6.21
*/
#include <iostream>
#include <vector>
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
    vector<int> v1,v2=v1,v3(v2),v4{1,2,3},v5={1,2,3,4},v6(v5.begin(),v5.end());
    print(v1);cout<<endl;
    print(v3);cout<<endl;
    print(v2);cout<<endl;
    print(v4);cout<<endl;
    print(v5);cout<<endl;
    print(v6);cout<<endl;
    return 0;
}
