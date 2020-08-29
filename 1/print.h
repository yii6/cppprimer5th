/*Author
	whulinus 1034765650@qq.com
Program
	print integers from a to b decreasingly. 
History
	version 1.0
	2016.5.19
*/
#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <vector>
#include <string>
#include "swap.h"
inline void print(int a,int b) {
	if(a<b)
		swap(a,b);
	while(--a>b)
        std::cout<<a<<std::endl;
}
inline void print(std::vector<std::string> &vec) {
	for(auto i:vec)
            std::cout<<i<<" ";
}
inline void print(std::vector<int> &vec) {
	for(auto i:vec)
            std::cout<<i<<" ";
}
#endif 
