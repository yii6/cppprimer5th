/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 17.9
History
    version 1.0 2016.9.19
*/
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
bitset<32> dtob(int i) {
    bitset<32> b;
    if(i) {
        if(i==1)
            b.set(0);
        else {
            int j=0;
            while(i!=1) {
                if(i%2)
                    b.set(j);
                i/=2;
                ++j;
            }
            b.set(j);
        }
    }
    return b;
}
int main() {
    int i=1010101;
    cout<<dtob(i).to_string()<<endl;
    return 0;
}
