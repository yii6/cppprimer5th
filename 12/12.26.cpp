/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.26
 *History
 *	ver 1.0 2016.7.12
 */
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
using namespace::std;
int main(int argc,char* argv[]){
	ifstream in("essay.txt");
	int n;
	in>>n;
	allocator<string> as;
	auto const p=as.allocate(n);
	string s;
	auto q=p;
	while(in>>s&&q!=p+n)
		as.construct(q++,s);
	const size_t size=q-p;
	while(q!=p){
		cout<<*(--q)<<" ";
		as.destroy(q);
	}
	cout<<endl;
	as.deallocate(p,n);
	return 0;
}
