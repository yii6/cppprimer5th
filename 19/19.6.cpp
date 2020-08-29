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
#include "Query.cpp"
using namespace std;
using namespace chapter15;
int main() {
    Query_base *q=new AndQuery(Query("fiery"),Query("bird"));
    Query_base *q1=new OrQuery(Query("fiery"),Query("bird"));
    AndQuery *aq=dynamic_cast<AndQuery *>(q);
    AndQuery *aq1=dynamic_cast<AndQuery *>(q1);
    if(typeid(*aq)==typeid(AndQuery))
        cout<<"success."<<endl;
//	if(typeid(*aq1)==typeid(AndQuery))
//		cout<<"success."<<endl;
    try {
        AndQuery &aq2=dynamic_cast<AndQuery &>(*q);
    }
    catch(bad_cast) {
        cout<<"unsuccess."<<endl;
    }
    if(typeid(*q)==typeid(*q1))
        cout<<"same."<<endl;
    if(typeid(*q)==typeid(AndQuery))
        cout<<"*q is AndQuery."<<endl;
    if(typeid(*q1)==typeid(AndQuery))
        cout<<"*q1 is AndQuery."<<endl;
    return 0;
}
