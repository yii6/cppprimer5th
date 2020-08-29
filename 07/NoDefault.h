/*Author
	whulinus 1034765650@qq.com
Program
	the function of default constructor.
History
	version 1.0  
	2016.6.9 
*/
#ifndef NODEFAULT_H
#define NODEFAULT_H
#include <string>
struct NoDefault{
	NoDefault(int);
};
struct C{
	C():mymem(0){}
private:
	NoDefault mymem;
};
#endif

