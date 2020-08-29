/*
Author
    whulinus 1034765650@qq.com
Program
    use lambda to capture an int and decrease it until it equals 0, return a bool to
point whether the paraeter is 0.
History
    version 1.0
    2016.7.2
*/
#include <iostream>
using namespace std;
void whether0(int a) {
    auto f=[&]()->bool{
        if(a>0) {
            --a;
            return false;
        }
        else
            return true;
    };
    while(!f())
        cout<<a;
}

int main(int argc,char *argv[]) {
    whether0(3);
    return 0;
}
