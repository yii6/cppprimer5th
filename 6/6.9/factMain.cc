/*Author
	whulinus 1034765650@qq.com
Program
	understand how my compiler supports separate compilation. 
History
	version 1.0
	2016.5.13
*/
#include <iostream>
#include "Chapter6.h"
using namespace std;
int main() {
    int num;
    cout<<"Enter a number:"<<endl;
    cin>>num;
    cout<<"The factorial is: "<<fact(num)<<endl;
    return 0;
}
