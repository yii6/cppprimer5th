/*  
Author
	whulinus 1034765650@qq.com
Program
	exercise 9.47 
History
	version 1.0
	2016.6.28
*/
#include <iostream>
#include <string> 
using namespace std;

int main(int argc,char *argv[]) {
    string s{"ab2c3d7R4E6"};
    string::size_type pos=0;
    string num{"0123456789"},alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    while((pos=s.find_first_of(num,pos))!=string::npos){
    	cout<<pos<<" ";
    	++pos;
	}
	pos=0;
	while((pos=s.find_first_of(alpha,pos))!=string::npos){
    	cout<<pos<<" ";
    	++pos;
	}
/*
while((pos=s.find_first_not_of(alpha,pos))!=string::npos){
    	cout<<pos<<" ";
    	++pos;
	}
	pos=0;
	while((pos=s.find_first_not_of(num,pos))!=string::npos){
    	cout<<pos<<" ";
    	++pos;
	}
//*/ 
    return 0;
}
