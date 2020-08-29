/*Author
	whulinus 1034765650@qq.com
Program
	replace all the characters with X using range for loop. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s="Please ";
    for(auto &c:s)
        c='X';
    cout<<s<<endl;
    return 0;
}
