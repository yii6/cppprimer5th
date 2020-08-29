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
inline void swap(int *a,int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
inline void swapp(int *(&p),int *(&q)){
	int *tmp=p;
	p=q;
	q=tmp;
}
#endif 
