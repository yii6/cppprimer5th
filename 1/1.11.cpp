/*Author
	whulinus 1034765650@qq.com
Program
	ask the user to enter two numbers a and b, print integers from a to b decreasingly. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include "print.h"
using namespace std;

int main() {
    int a,b;
    cout<<"Please enter two numbers:"<<endl;
    cin>>a>>b;
    print(a,b);
    return 0;
}
