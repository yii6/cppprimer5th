/*Author
	whulinus 1034765650@qq.com
Program
	judge whether a string has capital letters. Write another function to change
a string to lower form.
History
	version 1.0
	2016.5.15
*/

#include <iostream>
#include <string>
#include "mstring.h"
using namespace std;

int main() {
    string s;
    cout<<"Enter a string:"<<endl;
    cin>>s;
    if(isupper(s)) {
        cout<<s<<" has capital letters."<<endl;
        tolower(s);
    }
    cout<<"the lower form: "<<s<<endl;
    return 0;
}
