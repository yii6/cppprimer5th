/*Author
	whulinus 1034765650@qq.com
Program
	input two integers x,0, thorw out an exception.
History
	version 1.0
	2016.5.12
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;
    if(y==0)
    	throw runtime_error("divisor can't be 0.");
    cout<<x/y<<endl;
    return 0;
}
