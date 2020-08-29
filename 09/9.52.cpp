/*
Author
    whulinus 1034765650@qq.com
Program
    use stack to process expressions with braclets.
History
    version 1.0
    2016.6.29
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("9.52.txt");
    stack<char> cs,sc;
    string s;
    while(getline(in,s))
        for(auto c:s)
            if(c==')') {
                while(cs.top()!='(') {
                    sc.push(cs.top());
                    cs.pop();
                }
                cs.pop();
                while(!sc.empty()) {
                    cs.push(sc.top());
                    sc.pop();
                }
            }
            else
                cs.push(c);
    while(!cs.empty()){
    	cout<<cs.top();
    	cs.pop();
	}
    return 0;
}
