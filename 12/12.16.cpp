/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.16
 *History
 *	ver 1.0 2016.7.9
 */
#include <memory>
#include <iostream>
using namespace::std;
int main(int argc,char* argv[]){
	unique_ptr<int> p1(new int(1));
	unique_ptr<int> p2(p1);
	unique_ptr<int> p3;
	p3=p1;
	return 0;
}
