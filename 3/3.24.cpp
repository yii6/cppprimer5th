/*Author
	whulinus 1034765650@qq.com
Program
	exercise 3.24
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> c;
    int temp;
    while(cin>>temp)
        c.push_back(temp);
    auto n=c.size();
    auto j=c.begin(),k=c.end();
    if(c.empty()) {
        cout<<"please enter at least one number"<<endl;
        return -1;
    }
    else if(n==1)
        cout<<*j<<" don't have a pair"<<endl;
    else {
        for(auto i=j; i!=k-1; i++)
            cout<<*i+*(i+1)<<" ";
        cout<<endl;
    }
    for(auto i=j; i<j+(n+1)/2; i++)
        cout<<*i+*(k-1-i+j)<<" ";
    cout<<endl;
    return 0;
}
