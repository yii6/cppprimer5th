/*Author
	whulinus 1034765650@qq.com
Program
	function factorial.
History
	version 1.0
	2016.5.12
*/

#include <iostream>
using namespace std;

int fact(int val) {
    if(val==1||val==0)
        return 1;
    return val*fact(val-1);
}
int main() {
    int num;
    cout<<"Enter a number:"<<endl;
    cin>>num;
    cout<<"The factorial is: "<<fact(num)<<endl;
    return 0;
}
