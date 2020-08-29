/*Author
	whulinus 1034765650@qq.com
Program
	exercise 4.31
History
	version 1.0
	2016.5.7
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ivec(5);
    vector<int>::size_type cnt=ivec.size();
    /* 
	for(vector<int>::size_type ix=0; ix!=ivec.size(); ++ix,--cnt)
        ivec[ix]=cnt;
    for(auto a:ivec)
        cout<<a<<" ";
    cout<<endl;
    cnt=ivec.size();
    //*/ 
    for(vector<int>::size_type ix=0; ix!=ivec.size(); ix++,cnt--)
        ivec[ix]=cnt;  
    /* 
    for(auto a:ivec)
        cout<<a<<" ";
    cout<<endl;
    //*/
    return 0;
}
