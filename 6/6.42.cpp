/*Author
	whulinus 1034765650@qq.com
Program
	print out words with default arguments.
History
	version 1.0
	2016.5.19
*/

#include <iostream>
#include <string>
using namespace std;

string make_plural(size_t ctr, const string &word,
                   const string &ending={'s'}) {
    return (ctr>1)?word+ending:word;
}
int main() {
    cout<<make_plural(1,"success")<<endl;
    cout<<make_plural(2,"success","es")<<endl;
    cout<<make_plural(1,"failure")<<endl;
    cout<<make_plural(2,"failure")<<endl;
    return 0;
}
