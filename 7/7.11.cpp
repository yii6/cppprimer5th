/*Author
	whulinus 1034765650@qq.com
Program
	use Sales_data class.
History
	version 1.0
	2016.5.28
*/
#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
	Sales_data def;
	print(cout,def);
	Sales_data bN("isbn111");
	print(cout,bN);
	Sales_data bqr("isbn000",2,2.5);
	print(cout,bqr);
	Sales_data istreamS(cin);
	print(cout,istreamS);
	return 0;
}
