/*Author
	whulinus 1034765650@qq.com
Program
	print out the content of vector object.
History
	version 1.0
	2016.5.17
*/

#include <iostream>
#include <vector>
using namespace std;

void recursive(vector<int> vec,vector<int>::size_type st) {
    if(st==vec.size())
        return;
    cout<<vec[st];
    recursive(vec,++st);
}

int main() {
    vector<int> score{1,2,3,4};
    recursive(score,0);
    return 0;
}
