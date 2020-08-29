/*Author
	whulinus 1034765650@qq.com
Program
	exercise 7.27
History
	version 1.0
	2016.6.3
*/
#include <iostream>
#include "Screen&.h"
using namespace std;

int main() {
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout<<"\n";
    myScreen.display(cout);
    cout<<"\n";
}
