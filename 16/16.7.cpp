/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.5 
History
    version 1.0
    2016.8.15
*/
#include <iostream>
#include <string>
using namespace std;
template <typename T,unsigned N>constexpr size_t si(T (&arr)[N]){
	return N;
}
int main(int argc,char *argv[]) {
	string arr[]={"wo","ri","a"};
	cout<<si(arr)<<endl;
    return 0;
}
