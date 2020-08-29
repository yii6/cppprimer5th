/*Author
	whulinus 1034765650@qq.com
Program
	input some words, print out the repeated one or a message no word repeated.
History
	version 1.0
	2016.5.11
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string word,preword;
    bool flag=true;
    while(cin>>word) {
        if(word==preword) {
            cout<<"The repeated word is: "<<preword<<endl;
            flag=false;
            break;
        }
        preword=word;
    }
    if(flag)
        cout<<"No word repeated."<<endl;
    return 0;
}
