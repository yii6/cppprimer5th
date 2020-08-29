/*Author
	whulinus 1034765650@qq.com
Program
	exercise 2.38 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;
int main(){
	int i=0,&cj=i;
	const int ci=i,&ck=ci,*p=&ci;
	//same
	auto a=i;
	decltype(i) x=i;
	// different
	auto b=ci;b=1;
	decltype(ci) y=ci;
	//the following is wrong,y is const int
	//y=1;
	auto c=cj;c=b;
	decltype(cj) z=b;
	decltype(ck+0) zk0=b;
	decltype(ck) zk=b;
	decltype(*p) d=b;
	cout<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<endl;
	z=2;
	//zk0 is int
	zk0=2;
	//zk is const int
	//zk=2;
	//d is const int&
	//d=3;
	cout<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<endl;
	return 0;
}

