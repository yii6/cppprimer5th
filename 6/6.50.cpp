/*Author
	whulinus 1034765650@qq.com
Program
	function match.
History
	version 1.0
	2016.5.20
*/

#include <iostream>
using namespace std;

void f(){
	cout<<"f()"<<endl;
}
void f(int){
	cout<<"f(int)"<<endl;
}
void f(int,int){
	cout<<"f(int,int)"<<endl;
}
void f(double,double=3.14){
	cout<<"f(oduble,doube=3.14)"<<endl;
}

int main() {
    //f(2.4,32);//ambiguous
    f(32);
    f(42,0);
    f(2.5,4.6);
    return 0;
}
