/*Author
	whulinus 1034765650@qq.com
Program
	List three ways to define a vector and give it ten elements,
 each with the value 42.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a(10,42);
    vector<int> b{42,42,42,42,42,42,42,42,42,42};
    vector<int> c;
    vector<int> d(10);
    int i=10;
    while(i--){
    	c.push_back(42);
    	d[i]=42;
	}
    return 0;
}
