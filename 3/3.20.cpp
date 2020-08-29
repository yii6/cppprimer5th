/*Author
	whulinus 1034765650@qq.com
Program
	exercise 3.20
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
    if(c.empty()) {
        cout<<"please enter at least one number"<<endl;
        return -1;
    }
    else if(n==1)
        cout<<c[0]<<" don't have a pair"<<endl;
    else {
        for(decltype(n) i=0; i<n-1; i++)
            cout<<c[i]+c[i+1]<<" ";
        cout<<endl;
    }
    for(decltype(n) i=0; i<(n+1)/2; i++)
        cout<<c[i]+c[n-1-i]<<" ";
    cout<<endl;
    return 0;
}
