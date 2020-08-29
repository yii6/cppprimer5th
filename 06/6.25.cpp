/*Author
	whulinus 1034765650@qq.com
Program
	accept two arguments, combine them into a string and print out it.
	c:\>6.25.exe argu1 argu2
History
	version 1.0
	2016.5.16
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    for(int i=1; i<argc; ++i)
        s+=argv[i];
    cout<<s<<endl;
    return 0;
}
