/*Author
	whulinus 1034765650@qq.com
Program
	fuction with a istream& argument.
History
	version 1.0
	2016.6.13 
*/
#include <iostream>
#include <string>
using namespace std;

istream& print(istream& is) {
	string s;
	while(getline(is,s))
	cout<<s<<endl;
	is.clear();
	return is;
}

int main() {
	istream &is=print(cin);
	cout<<is.rdstate()<<endl;
	return 0;
}
