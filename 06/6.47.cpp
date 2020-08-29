/*Author
	whulinus 1034765650@qq.com
Program
	print out the content of vector object.
History
	version 1.0
	2016.5.20
*/

#include <iostream>
#include <vector>
using namespace std;
//#define NDEBUG
void print(vector<int> vec) {
	auto size=vec.size();
	#ifndef NDEBUG
	cerr<<__func__<<": vector size is "<<size<<endl;
	#endif 
    if(size==0)
        return;
    cout<<vec[size-1]<<endl;
    vec.pop_back();
    print(vec);
}

int main() {
    vector<int> score{4,5,9,3};
    print(score);
    return 0;
}
