/*Author
	whulinus 1034765650@qq.com
Program
	delete all the punctuation in a string.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin>>s;
    for(auto &c:s)
        if(ispunct(c))
            c=' ';
    cout<<s<<endl;
    return 0;
}
