/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	exxercise 14.38 
 *History
 *	ver 1.0 2016.7.28
 */
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>
#include "If_then.h"
using namespace::std;
int main(){
	ifstream cin("essay.txt");
	int words=0;
	vector<int> vi;
	istream_iterator<string> iis(cin),eof;
	vector<string> vs(iis,eof);
	ostream_iterator<int> out(cout," ");
	for(int i=1;i<10;++i)
		words+=count_if(vs.begin(),vs.end(),If_then(i));
	vi.push_back(words);
	vi.push_back(vs.size()-words);
	copy(vi.begin(),vi.end(),out);
	return 0;
}

