/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.10
History
    version 1.0 2016.9.20
*/
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {
	bitset<32> b;
	vector<int> v{1,2,3,5,8,13,21};
	for(auto &c:v)
		b.set(c);
	cout<<b<<endl;
    return 0;
}
