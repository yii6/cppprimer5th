/*Author
	whulinus 1034765650@qq.com
Program
	exercise 2.33 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;
int main(){
	int i=0,&r=i;
	auto a = r;
	const int ci=i,&cr=ci;
	auto b=ci;
	auto c=cr;
	auto d=&i;
	auto e=&ci;
	auto &g=ci;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<g<<endl;
	a=42;
	b=42;
	c=42;
	//d=42;
	//e=42;
	//g=42;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<g<<endl;
	return 0;
}

