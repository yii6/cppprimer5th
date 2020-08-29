/*Author
	whulinus 1034765650@qq.com
Program
	write a function, open a file with read mode.
History
	version 1.0
	2016.6.14 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read(istream& is,vector<string> &vec){
	string s;
	while(is>>s)
	vec.push_back(s);
}

int main(int argc,char *argv[]){
	ifstream in(argv[1]);
	vector<string> vec;
	read(in,vec);
	for(auto &c:vec)
	cout<<c<<endl;
	return 0;
}
