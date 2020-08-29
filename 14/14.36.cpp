/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	exxercise 14.36 
 *History
 *	ver 1.0 2016.7.26
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "PrintString.h"
using namespace::std;
int main(){
	ifstream in("essay.txt");
	vector<string> v;
	PrintString ps;
	string s;
	do{
		s=ps(in);
		v.push_back(s);
	}while(s!="");
	for(auto &c:v)
	ps(c);
	return 0;
}

