/*Author
	whulinus 1034765650@qq.com
Program
	use pointer to change values in an array.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;
int main() {
    int arr[]={1,2},*p=arr;
    while(p!=end(arr)){
    	*p=0;
    	++p;
	}
    return 0;
}
