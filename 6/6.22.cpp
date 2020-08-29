/*Author
	whulinus 1034765650@qq.com
Program
	swap two int*.
History
	version 1.0
	2016.5.16
*/

#include <iostream>
#include "swap.h"
using namespace std;

int main() {
    int a,b,*p=&a,*q=&b;
    cout<<p<<" "<<q<<endl;
    swapp(p,q);
    cout<<p<<" "<<q<<endl;
    return 0;
}
