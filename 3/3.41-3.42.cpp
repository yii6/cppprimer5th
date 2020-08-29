/*Author
	whulinus 1034765650@qq.com
Program
	use array to initialize vector, use vector to initialize array. 
History
	version 1.0
	2016.5.20
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[]= {1,2,3};
    vector<int> vec(begin(arr),end(arr));
    //exercise 3.42
	int arrc[vec.size()];
    int i=0;
    for(auto c:vec) 
        arrc[i++]=c;
    return 0;
}
