/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.14
 *History
 *	ver 1.0 2016.7.9
 */
#include <memory>
#include <iostream>
using namespace::std;
struct destination{};
struct connection{};
connection connect(destination* d){
	connection c;
	return c;
}
void disconnect(connection &c){}
void end_connection(connection *p){disconnect(*p);}
void f(destination &d){
	connection c=connect(&d);
	shared_ptr<connection> p(&c,end_connection);	
}
int main(int argc,char* argv[]){
	destination d;
	f(d);
	return 0;

}
