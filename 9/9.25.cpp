/*  
Author
	whulinus 1034765650@qq.com
Program
	use single iterator erase to delete elements from list and vector.
History
	version 1.0
	2016.6.23
*/
#include <iostream>
#include <vector>
using namespace std;
#include "print.h"

int main(int argc,char *argv[]) {
    vector<int> v{1,2};
	auto e=v.erase(++v.begin(),++v.begin()); 
	print(v);
	cout<<*e;
    return 0;
}
