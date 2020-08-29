/*
Author
    whulinus 1034765650@qq.com
Program
    use lambda to rewrite comparing isbn of two Sales_data objects..
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Sales_data.h"
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.12.txt");
    vector<Sales_data> vs;
    Sales_data data;
    while(read(in,data))
        vs.push_back(data);
    sort(vs.begin(),vs.end(),[](const Sales_data &s1,const Sales_data &s2){return s1.isbn()<s2.isbn();});
    for(auto &c:vs)
        print(cout,c)<<endl;
    return 0;
}
