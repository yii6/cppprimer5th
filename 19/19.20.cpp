/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *  exercise 19.20
 *History
 *	ver 1.0 2016.10.22
 */
#include <fstream>
#include <iostream>
#include "TextQuery.h"
using namespace::std;
void runQuery (ifstream &infile){
	TextQuery tq(infile);
	ifstream in("word.txt");
	while(true){
		cout<<"enter word to look for, or q to quit: ";
		string s;
		if(!(in>>s)||s=="q") break;
		print(cout,tq.query(s))<<endl;
	}
}

int main(int argc,char* argv[]){
	ifstream rin("essay.txt");
	runQuery(rin);
	return 0;
}
