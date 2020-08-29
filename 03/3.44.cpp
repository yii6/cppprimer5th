/*Author
	whulinus 1034765650@qq.com
Program
	use 3 different way to cout an array by using type alias.
History
	version 1.0
	2016.5.20
*/
#include <iostream>
using namespace std;
typedef int int_array[4];
using int_arr=size_t;
int main() {
    int ia[2][4]= {1,2,3,4,5,6,7,8};
    for(int_array &p:ia)
        for(int q:p)
            cout<<q<<' ';
    cout<<endl;
    for(int_arr p=0; p!=2; p++)
        for(int_arr q=0; q!=4; q++)
            cout<<ia[p][q]<<' ';
    cout<<endl;
    for(int_array *p=ia; p!=ia+2; p++)
        for(int *q=*p; q!=*p+4; q++)
            cout<<*q<<' ';
    cout<<endl;
    return 0;
}
