/*  
Author
	whulinus 1034765650@qq.com
Program
	use list<int> to initialize vector<double>.
History
	version 1.0
	2016.6.21
*/
#include <iostream>
#include <vector>
#include <list>
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
    list<int> li{1,2,34,5};
    vector<int> vi(10,2);
    vector<double> vd1(li.begin(),--li.end()),vd2(vi.begin()+4,vi.end());
    print(vd1);cout<<endl;
    print(vd2);cout<<endl;
    return 0;
}
