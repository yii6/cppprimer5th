/*Author
	whulinus 1034765650@qq.com
Program
	use filename as an argument and pass it to main function, save output to a file.
History
	version 1.0
	2016.6.15
*/
#include <iostream>
#include <fstream>
#include "Sales_data.h"
using namespace std;

int main(int argc,char *argv[]) {
	ifstream in(argv[1]);
	Sales_data total;
	if(read(in,total)){
		Sales_data trans;
		while(read(in,trans))
			if(total.isbn()==trans.isbn())
				total.combine(trans);
			else{
				ofstream out(argv[2],ofstream::app);
				print(out,total)<<endl;
				total=trans;
			}
		ofstream out(argv[2],ofstream::app);
		print(out,total)<<endl;
	}
	else{
		cerr<<"No data?"<<endl;
		return -1;
	}
	return 0;
}
