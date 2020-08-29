/*Author
	whulinus 1034765650@qq.com
Program
	exercise 2.35 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;
int main(){
	const int i=42;
	auto j=i;
	const auto &k=i;
	auto *p=&i;
	const auto j2=i,&k2=i;
	cout<<j<<" "<<k<<" "<<*p<<" "<<j2<<" "<<k2<<endl;
	j=0;
	//an error occurs next
	//k=0;
	//*p=0;
	//j2=0;
	//k2=0;
	p=&j;
	cout<<j<<" "<<k<<" "<<*p<<" "<<j2<<" "<<k2<<endl;
	return 0;
}

