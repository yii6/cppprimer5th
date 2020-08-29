/*Author
	whulinus 1034765650@qq.com
Program
	change the value of a pointer, the object a pointer points. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;

int main(){
	int v1=1,*v2=&v1,v3=2;
    cout<<"v1 is "<<v1<<" v2 is "<<v2<<" *v2 is "<<*v2<<" v3 is "<<v3<<endl;
    *v2=0;
    cout<<"v1 is "<<v1<<" v2 is "<<v2<<" *v2 is "<<*v2<<" v3 is "<<v3<<endl;
    v2=&v3;
    cout<<"v1 is "<<v1<<" v2 is "<<v2<<" *v2 is "<<*v2<<" v3 is "<<v3<<endl;
	return 0;
}
