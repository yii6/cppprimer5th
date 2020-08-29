/*Author
	whulinus 1034765650@qq.com
Program
	find odd numbers then double them.
History
	version 1.0
	2016.5.20
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ivec{1,2,3,4,5,6,7};
    for(int &c:ivec)
        c%2?(c*=2):1;
    return 0;
}
