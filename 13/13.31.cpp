/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 13.31
 *History
 *	ver 1.0 2016.7.16
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "HasPtr.h"
using namespace::std;
int main(int argc,char* argv[]){
	vector<HasPtr> vh{HasPtr("dca"),HasPtr("db"),HasPtr("caaaa")};
	sort(vh.begin(),vh.end());
	for(auto &d:vh)
		cout<<*d.ps<<" ";
	cout<<endl;
	return 0;
}
