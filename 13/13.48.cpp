/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	String.h
 *History
 *	ver 1.0 2016.7.19
 */
#include <vector>
#include <iostream>
#include "pString.h"
using namespace::std;
int main(int argc,char* argv[]){
	vector<String> vs;
	char *c="aaa";
	vs.push_back("aa");
	vs.push_back(c);
	vs.push_back(String());
	return 0;
}
