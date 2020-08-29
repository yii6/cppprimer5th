/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.27
History
    version 1.0
    2016.7.6
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

int main(int argc,char *argv[]) {
    multimap<string,vector<int>> msi{{"aa",{1,2}},{"ed",{3,2}}};
    auto iter=msi.find("aa");
    for(auto c:iter->second)
    cout<<c<<" ";
    return 0;
}
