/*Author
	whulinus 1034765650@qq.com
Program
	use class and function to rewrite transaction processing program.
History
	version 1.0
	2016.5.22
*/
#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
	Sales_data total;
	if(read(cin,total)){
		Sales_data trans;
		while(read(cin,trans))
			if(total.isbn()==trans.isbn())
				total.combine(trans);
			else{
				print(cout,total)<<endl;
				total=trans;
			}
		print(cout,total)<<endl;
	}
	else{
		cerr<<"No data?"<<endl;
		return -1;
	}
	return 0;
}
