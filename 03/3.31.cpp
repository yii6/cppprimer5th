/*Author
	whulinus 1034765650@qq.com
Program
	array.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;
int main() {
    int arr[10],j=0;
    for(auto &i:arr) {
        i=j;
        j++;
        cout<<i<<" ";
    }
    return 0;
}
