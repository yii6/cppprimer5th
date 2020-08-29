/*Author
	whulinus 1034765650@qq.com
Program
	use iterator to complete dividing score sections.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<unsigned> c(11,0);
    unsigned temp;
    auto j=c.begin();
    while(cin>>temp)
        if(temp<=100)
            ++*(j+temp/10);
    for(auto i=j; i!=c.end(); i++)
        cout<<*i<<" ";
    cout<<endl;
    return 0;
}
