/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	exxercise 14.37 
 *History
 *	ver 1.0 2016.7.26
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "If_then.h"
using namespace::std;
int main(){
	ifstream in("numbers.txt"),input("14.37.txt");
	int num,tmp,replace;
	input>>num>>replace;
	vector<int> vi;
	while(in>>tmp)
		vi.push_back(tmp);
	replace_if(vi.begin(),vi.end(),If_then(num),replace);
	for(auto c:vi)
	cout<<c<<" ";
	cout<<endl;
	return 0;
}

