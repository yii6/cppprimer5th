/*Author
	whulinus 1034765650@qq.com
Program
	print out vector object.
History
	version 1.0
	2016.5.19
*/
#include <string>
#include <vector>
#include "print.h"
using namespace std;

int main() {
    vector<int> v1,v2(10),v3(10,42),v4{10},v5{10,42};
    vector<string> v6{10},v7{10,"hi"};
   	print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
    print(v7);
    return 0;
}
