/*Author
	whulinus 1034765650@qq.com
Program
	some math fuctions. 
History
	version 1.0
	2016.5.20
*/
#ifndef MMATH_H
#define MMATH_H
#include <iostream>
#include <stdexcept>
inline int abs(const int i) {
    if(i<0)
        return -i;
    return i;
}
inline int add(int a ,int b){
	return a+b;
}
inline int mminus(int a ,int b){
	return a-b;
}
inline int times(int a ,int b){
	return a*b;
}
inline int divide(int a ,int b){
	do{
		try {
            if(b==0)
                throw std::runtime_error("divisor can't be 0.");
            return a/b;
        }
        catch(std::runtime_error err) {
            std::cout<<err.what()
                <<"\nTry again? Enter y or n"<<std::endl;
            char c;
            std::cin>>c;
            if(!std::cin||c=='n')
                break;
            std::cout<<"Enter another two numbers:"<<std::endl;
        }
	}while(std::cin>>a>>b);
	return -1;
}
#endif 
