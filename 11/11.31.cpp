/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.31
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
    multimap<string,string> msi{{"au","boo"},{"au","coo"}};
    auto iter=msi.find("au");
    if(iter!=msi.end())
    msi.erase(iter);
    for(auto c:msi)
    cout<<c.second<<" ";
    return 0;
}
