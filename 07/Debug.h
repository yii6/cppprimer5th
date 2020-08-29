/*Author
	whulinus 1034765650@qq.com
Program
	Debug class.
History
	version 1.0  
	2016.6.11 
*/
#ifndef DEBUG_H
#define DEBUG_H
#include <string>
struct Debug{
	constexpr Debug(bool b=true):hw(b),io(b),other(b){}
	constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}
	constexpr bool any(){return hw||io||other;}
	void set_io(bool b){io=b;}
	void set_hw(bool b){io=b;}
	void set_other(bool b){other=b;}
private:
	bool hw;
	bool io;
	bool other;
}; 
	
#endif

