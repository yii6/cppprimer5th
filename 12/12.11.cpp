/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.10
 *History
 *	ver 1.0 2016.7.8
 */
#include <memory>
#include <iostream>
using namespace::std;
void process(shared_ptr<int> ptr){
	cout<<ptr.use_count();
}
int main(int argc,char* argv[]){
	shared_ptr<int> p(new int(32));
	process(shared_ptr<int>(p.get()));
	return 0;
}
