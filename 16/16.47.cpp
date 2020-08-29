/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.47
History
    version 1.0 2016.9.8
*/
#include <iostream>
#include <utility>
using namespace std;
template<typename F,typename T1,typename T2>void flip(F f,T1 &&t1,T2 &&t2){
	f(forward<T2>(t2),forward<T1>(t1));
}
void g(int &&i,int &j){
	cout<<i<<" "<<++j<<endl;
}
int main() {
	int i=3;
	flip(g,i,42);
	cout<<i<<endl;
    return 0;
}
