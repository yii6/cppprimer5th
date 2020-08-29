/*Author
	whulinus 1034765650@qq.com
Program
	use 3 different way to cout an array.
History
	version 1.0
	2016.5.20
*/
#include <iostream>
using namespace std;
int main() {
    int ia[2][4]= {1,2,3,4,5,6,7,8};
    for(int (&p)[4]:ia)
        for(int q:p)
            cout<<q<<' ';
    cout<<endl;
    for(size_t p=0; p!=2; p++)
        for(size_t q=0; q!=4; q++)
            cout<<ia[p][q]<<' ';
    cout<<endl;
    for(int (*p)[4]=ia; p!=ia+2; p++)
        for(int *q=*p; q!=*p+4; q++)
            cout<<*q<<' ';
    cout<<endl;
    return 0;
}
