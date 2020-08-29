/*Author
	whulinus 1034765650@qq.com
Program
	exercise 3.23
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    for(auto i=arr.begin(); i!=arr.end(); i++) {
        *i*=2;
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
