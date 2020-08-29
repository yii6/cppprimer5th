/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 13.8
 *History
 *	ver 1.0 2016.7.14
 */
#include <iostream>
using namespace::std;
class numbered{
	int mysn;
	static int no;
public:
	friend void f(const numbered&);
	numbered(){mysn=no;++no;}
	numbered(const numbered& n){mysn=n.mysn+1;}
	numbered& operator=(const numbered &ne){return *this;}
};
int numbered::no=1;
void f(const numbered &s){
	cout<<s.mysn<<endl;
}
int main(int argc,char* argv[]){
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);
	return 0;
}
