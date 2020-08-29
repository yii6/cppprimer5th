/*Author
	whulinus 1034765650@qq.com
Program
	swap two integers. 
History
	version 1.0
	2016.5.19
*/
#ifndef SWAP_H
#define SWAP_H
inline void swap(int &a,int &b) {
	int c=a;
	a=b;
	b=c;
}
#endif 
