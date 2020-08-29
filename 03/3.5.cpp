/*Author
	whulinus 1034765650@qq.com
Program
	combine several strings into one big string, print it.
	combine several strings into one big string with space , print it.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    cout<<"Please enter several words:"<<endl;
    string word,total;
    cin>>total;
    /*
    while(cin>>word) {
        total+=" ";
        total+=word;
    }
  	//*/
    while(cin>>word)
    	total+=word;
    cout<<total<<endl;
    return 0;
}
