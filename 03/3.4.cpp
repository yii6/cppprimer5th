/*Author
	whulinus 1034765650@qq.com
Program
	compare two strings whether they are equal, if not print out the bigger one.
	compare two strings whether they have the same length, if not print out the longer one.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
using namespace std;


int main() {
    cout<<"Please enter two words"<<endl;
    string word1,word2;
    cin>>word1>>word2;
    if(word1>word2)
        cout<<word1<<endl;
    else if(word1==word2)
        cout<<"two words are equal!"<<endl;
    else
        cout<<word2<<endl;
    if(word1.size()>word2.size())
        cout<<word1<<endl;
    else if(word1.size()==word2.size())
        cout<<"the length are equal!"<<endl;
    else
        cout<<word2<<endl;
    return 0;
}
