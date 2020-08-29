/*Author
	whulinus 1034765650@qq.com
Program
	getline and cin
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    cout<<"Please enter some words"<<endl;
    string line;
    getline(cin,line);
    if(!line.empty()&&line.size()>0)
        cout<<line<<endl;
    cout<<"Please enter some words"<<endl;
    string word;
    while(cin>>word)
        cout<<word<<endl;
    return 0;
}
