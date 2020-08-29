/*Author
	whulinus 1034765650@qq.com
Program
	type conversion 
History
	version 1.0
	2016.5.8
*/

#include <iostream>
using namespace std;

int main() {
	int i=3;
	double d=1.5;
	i*=static_cast<int> (d);
    return 0;
}
