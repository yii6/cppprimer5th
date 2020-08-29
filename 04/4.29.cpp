/*Author
	whulinus 1034765650@qq.com
Program
	exercise 4.29
History
	version 1.0
	2016.5.6
*/

#include <iostream>
using namespace std;

int main() {
    int x[10];
    int *p=x;
	cout<<sizeof(x)/sizeof(*x)<<endl;
	cout<<sizeof(*p)/sizeof(p)<<endl;
    return 0;
}
