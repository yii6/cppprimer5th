/*Author
	whulinus 1034765650@qq.com
Program
	use cite variables to change the values of two integers.
History
	version 1.0
	2016.5.14
*/

#include <iostream>
#include "swap.h"
using namespace std;

int main() {
    int a,b;
    cout<<"Enter a="<<endl;
    cin>>a;
    cout<<"Enter b="<<endl;
	cin>>b;
    swap(a,b);
    cout<<"a="<<a<<" b="<<b<<endl;
    return 0;
}
