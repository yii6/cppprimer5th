/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 13.8
 *History
 *	ver 1.0 2016.7.14
 */
#include <iostream>
#include <vector>
#include "HasPtr.h"
using namespace::std;
void f(const HasPtr& rx, HasPtr x)
{
    cout<<"5"<<endl;
	std::vector<HasPtr> vec;
	cout<<"6"<<endl;
    vec.reserve(2);
    cout<<"7"<<endl;
    vec.push_back(rx);
    cout<<"8"<<endl;
    vec.push_back(x);
}
int main(int argc,char* argv[]){
	cout<<"1"<<endl;
	HasPtr h("acss"),p;
	cout<<"2"<<endl;
	p=std::move(h);
	cout<<"3"<<endl;
	HasPtr pr(h);
	cout<<"4"<<endl;
	HasPtr *pn=new HasPtr;
	cout<<"9"<<endl;
	f(*pn, *pn);
	return 0;
}
