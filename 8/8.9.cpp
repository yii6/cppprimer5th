/*Author
	whulinus 1034765650@qq.com
Program
	use the function to print an istringstream object.
History
	version 1.0
	2016.6.16
*/
#include <iostream>
#include <sstream>
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
	istringstream record("aaaa123");
	print(record);
	return 0;
}
