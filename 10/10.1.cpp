/*
Author
    whulinus 1034765650@qq.com
Program
    use count in header algorithm
History
    version 1.0
    2016.6.30
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.1.txt");
    int num;
    vector<int> vi;
    while(in>>num)
        vi.push_back(num);
    cout<<count(vi.begin(),vi.end(),35);
    return 0;
}
