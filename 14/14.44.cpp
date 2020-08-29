/*
Author
    whulinus 1034765650@qq.com
Program
    simple desktop calculator
History
    version 1.0
    2016.7.29
*/
#include <fstream>
#include <string>
#include <map>
#include <functional>
#include <iostream>
using namespace std;
inline int add(int i,int j) {
    return i+j;
}
struct divide {
    int operator()(int i,int j) {
        return i/j;
    }
};
int main(int argc,char *argv[]) {
 //   ifstream cin("14.44.txt");
    string symble;
    int a,b;
    auto mod=[](int i,int j) {
        return i%j;
    };
    map<string,function<int(int,int)>> calculator= {{"+",add},{"-",minus<int>()},{"/",divide()},{"*",[](int i,int j) {
                return i*j;
            }
        },{"%",mod}
    };
    cout<<"please enter a operator b:"<<endl;
    while(cin>>a>>symble>>b) {
        cout<<calculator[symble](a,b)<<endl;
        cout<<"please enter a operator b:"<<endl;
    }
    return 0;
}
