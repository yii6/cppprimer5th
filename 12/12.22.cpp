/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.20
 *History
 *	ver 1.0 2016.7.10
 */
#include <vector>
#include <memory>
#include <iostream>
#include <initializer_list>
#include "StrBlob.h"
using namespace::std;
int main(int argc,char* argv[]){
	initializer_list<string> il{"ab","cd","ef"};
	const StrBlob sb(il);
	for(auto b=sb.cbegin();b.rcurr()!=sb.cend().rcurr();b=b.incr())
		cout<<b.deref()<<" ";
	return 0;
}
