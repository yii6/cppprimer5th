/*  
Author
	whulinus 1034765650@qq.com
Program
	use single iterator erase to delete elements from list and vector.
History
	version 1.0
	2016.6.23
*/
#include <iostream>
#include <forward_list>
#include <string>
#include <fstream>
using namespace std;
#include "print.h"

void insertString(forward_list<string> &fl,string find,string in) {
    auto curr=fl.begin();
    auto pre=fl.before_begin();
    while(curr!=fl.end())
        if(*curr==find) {
            fl.insert_after(curr,in);
            return;
        }
        else{
        	pre=curr;
        	++curr;
		}
    fl.insert_after(pre,in);
}
int main(int argc,char *argv[]) {
    forward_list<string> fl{"I","love","you"};
    string find,ins;
    ifstream in("9.28.txt");
    while(in>>find>>ins) {
        insertString(fl,find,ins);
        print(fl);cout<<endl;
    }
    return 0;
}
