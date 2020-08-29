/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 15.36
History
    version 1.0
    2016.8.12
*/
#include <iostream>
#include <fstream>
#include "Query.h"
using namespace std;
int main(int argc,char *argv[]) {
	ifstream cin("essay.txt");
	TextQuery t(cin);
    Query q=Query("fiery") & Query("bird") | Query("wind");
    cout<<q<<endl;
    print(cout,q.eval(t));
    return 0;
}
