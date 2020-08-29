/*Author
	whulinus 1034765650@qq.com
Program
	exercise 3.22
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<string> s{"Good morning !\
It is really my honor to have this opportunity for\
a interview,I hope i can make a good performance today.\
I'm confident that I can succeed.Now i will introduce\
myself briefly I am 26 years old,born in shandong province."};
    auto i=s.begin();
    for(auto &j:*i)
        j=toupper(j);
    for(; i!=s.end(); i++)
        cout<<*i<<" ";
    cout<<endl;
    return 0;
}
