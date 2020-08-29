/*Author
	whulinus 1034765650@qq.com
Program
	replace all the characters with X using for loop and while loop. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s="Please ";
    for(auto n=s.size(); n>0; n--)
        s[n-1]='X';
    cout<<s<<endl;
    s="Please ";
    auto n=s.size();
    while(n--)
        s[n]='X';
    cout<<s<<endl;
    return 0;
}
