/*Author
	whulinus 1034765650@qq.com
Program
	input two strings, print out the short one;
History
	version 1.0
	2016.5.11
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1,s2;
    do {
    	cout<<"Please input two strings:"<<endl;
        cin>>s1>>s2;
        cout<<"The short one is: "<<(s1.size()<s2.size()?s1:s2)<<endl;
    }
    while(cin);
    return 0;
}
