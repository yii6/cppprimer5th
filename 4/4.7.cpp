/*Author
	whulinus 1034765650@qq.com
Program
	write 3 expression which will cause spill. 
History
	version 1.0
	2016.5.20
*/
#include <iostream>
using namespace std;

int main() {
    short int a=32767;
    ++a;
    unsigned int b=1;
    b-=2;
    unsigned short int c=65536;
    ++c;
    cout<<a<<' '<<b<<' '<<c<<endl;
    c=-1;
    cout<<c<<endl;
    return 0;
}
