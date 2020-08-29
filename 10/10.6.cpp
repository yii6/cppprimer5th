/*
Author
    whulinus 1034765650@qq.com
Program
    use fill_n.
History
    version 1.0
    2016.6.30
*/
#include <iostream>
#include <vector>
#include <iterator>
#include "print.h"
using namespace std;

int main(int argc,char *argv[]) {
	vector<int> vi{1,2,3,4,5},vec;
	vec.reserve(10);
	fill_n(vi.begin(),vi.size(),0);
	fill_n(back_inserter(vec),10,0);
	print(vi);cout<<endl;
	print(vec);
    return 0;
}
