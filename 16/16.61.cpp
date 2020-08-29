/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.61
History
    version 1.0 2016.9.134
*/
#include <iostream>
#include <memory>
template <typename T,typename ... Args>std::shared_ptr<T> mmake_shared(Args&&... args){
	std::shared_ptr<T> ret=new T(std::forward<Args>(args)...);
	return ret;
}
int main() {
    return 0;
}
