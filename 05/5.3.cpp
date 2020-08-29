/*Author
	whulinus 1034765650@qq.com
Program
	comma operator
History
	version 1.0
	2016.5.9
*/

#include <iostream>
using namespace std;

int main() {
    int sum=0,val=1;
    while(val<=10)
        sum+=val,++val;
    /*
    while(sum+=val,val<=9)
        ++val;
    */
    return 0;
}
