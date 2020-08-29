/*Author
	whulinus 1034765650@qq.com
Program
	write an expression to make sure a>b>c>d.
History
	version 1.0
	2016.5.20
*/
#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
    if(a>b&&b>c&&c>d)
    	cout<<"yes";
    return 0;
}
