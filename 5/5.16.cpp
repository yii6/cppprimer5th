/*Author
	whulinus 1034765650@qq.com
Program
	for and while loop.
History
	version 1.0
	2016.5.11
*/

#include <iostream>
using namespace std;

int main() {
    int num=0,sumw=0,sumw1=0,sumf=0,sumf1=0;
    /*
	while(cin>>num)
        sumw+=num;
    cout<<sumw<<endl;
    //*/
    for(int i=0; i<5; ++i)
        sumf+=i;
    cout<<sumf<<endl;
    for(int n=0; cin>>n;)
        sumw1+=n;
    cout<<sumw1<<endl;
    int i=0;
    while(i<5) {
        sumf1+=i;
        ++i;
    }
    cout<<sumf1<<endl;
    return 0;
}
