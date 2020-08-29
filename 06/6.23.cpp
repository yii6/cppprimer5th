/*Author
	whulinus 1034765650@qq.com
Program
	several print fuctions.
History
	version 1.0
	2016.5.16
*/

#include <iostream>
#include "print.h"
using namespace std;


int main() {
    int i=0,j[2]={0,1};
    print(&i,&i+1);
    print(begin(j),end(j));
    print(&i,1);
    print(j,2);
    print(&i);
    print(j);
    return 0;
}
