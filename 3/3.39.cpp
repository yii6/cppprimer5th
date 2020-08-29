/*Author
	whulinus 1034765650@qq.com
Program
	compare two strings and two cstrings. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    string s1="hello",s2("hello");
    if(s1==s1)
        cout<<"string  equal!"<<endl;
    else
        cout<<"string  not equal!"<<endl;
    char cs1[]="hi",cs2[]={'h','i','\0'};
    if(strcmp(cs1,cs2)==0)
        cout<<"c-style string  equal!"<<endl;
    else
        cout<<"c-style  string  not equal!"<<endl;
    return 0;
}
