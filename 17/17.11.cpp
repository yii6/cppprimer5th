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
using namespace std;
#define N 10
bitset<N> b;
void change(int i,bool t){
	b.set(i,t);
}
int main() {
	change(5,1);
	cout<<b<<endl;
    return 0;
}
