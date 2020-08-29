/*  
Author
	whulinus 1034765650@qq.com
Program
	use vector<char> to initialize string.
History
	version 1.0
	2016.6.25
*/
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main(int argc,char *argv[]) {
    vector<char> vi(3,'c');
    string s(vi.begin(),vi.end());
    cout<<s;
    return 0;
}
