/*Author
	whulinus 1034765650@qq.com
Program
	parameter, local variable, local static variable
History
	version 1.0
	2016.5.13
*/

#include <iostream>
using namespace std;

int count_calls(int i) {
    static int ctc=-1;
    ++ctc;
    --i;
    if(i)
        return count_calls(i);
    return ctc;
}
int main() {
    int num;
    cout<<"Enter a number:"<<endl;
    cin>>num;
    cout<<"The function has been called "<<count_calls(num)+1<<" times."<<endl;
    return 0;
}
