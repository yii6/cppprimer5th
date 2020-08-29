/*Author
	whulinus 1034765650@qq.com
Program
	use cite variables to realize reset function .
History
	version 1.0
	2016.5.14
*/

#include <iostream>
using namespace std;

void reset(int &i) {
    i=0;
}
int main() {
    int a;
    cout<<"Enter a number"<<endl;
    cin>>a;
    reset(a);
    cout<<"a="<<a<<endl;
    return 0;
}
