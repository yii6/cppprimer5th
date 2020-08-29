/*Author
	whulinus 1034765650@qq.com
Program
	use pointer to call arithmetic functions.
History
	version 1.0
	2016.5.21
*/

#include <iostream>
#include <vector>
#include "mmath.h" 
using namespace std;
int f(int ,int){
	return 0;
}
using Pf=int (*)(int ,int);
int main() {
	Pf pf=f;
    vector<Pf> vec{pf};
    vec.push_back(add);
    vec.push_back(times);
    vec.push_back(divide);
    vec.push_back(mminus);
    for(int i=0;i<5;++i)
    cout<<vec[i](1,0)<<endl;
    return 0;
}
