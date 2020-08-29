/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.6
History
    version 1.0 2016.10.15
*/
#include <typeinfo>
#include <iostream>
#include <string>
#include "Query.cpp"
#include "Sales_data.h" 
using namespace std;
using namespace chapter15;
int main() {
    Query_base *q=new AndQuery(Query("fiery"),Query("bird"));
    int arr[10];
    cout<<typeid(42).name()<<" "
    	<<typeid(arr).name()<<" "
    	<<typeid(Sales_data).name()<<" "
    	<<typeid(string).name()<<" "
    	<<typeid(q).name()<<" "
    	<<typeid(*q).name()<<endl;
    return 0;
}
