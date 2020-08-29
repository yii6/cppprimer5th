/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 14.51
History
    version 1.0
    2016.7.31
*/
#include <iostream>
using namespace std;
class SmallInt{
	friend operator+(const SmallInt &,const SmallInt &);
public:
	SmallInt(int i=0){}
	operator int()const{return val;}
private:
	size_t val;
};
struct LongDouble{
	LongDouble(double d =0.0){}
	operator double();
	operator float(){
	}
	LongDouble operator+(const SmallInt &s){cout<<"1";}
};
LongDouble operator+(LongDouble &l,double d){cout<<"2";}

void calc(int){}
void calc(LongDouble);
int main(int argc,char *argv[]) {
 	LongDouble l;
 	
 //	int e1=l;
 	float e2=l;
	double d;
	calc(d);
	SmallInt s;
	//l=s+l;
	l=l+s;
	d=s.operator int()+3.14;
    return 0;
}
