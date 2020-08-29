/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 11.11
History
    version 1.0
    2016.7.4
*/
#include <iostream>
#include <set>
#include "Sales_data.h"
using namespace std;
bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs){
	return lhs.isbn()<rhs.isbn();
}
int main(int argc,char *argv[]) {
    multiset<Sales_data,bool (*)(const Sales_data &,const Sales_data &)> bookstore(compareIsbn);
    return 0;
}
