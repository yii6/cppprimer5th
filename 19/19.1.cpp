/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 19.1
History
    version 1.0 2016.10.12
*/
#include <cstdlib>
#include <stdexcept>
void *operator new(size_t n){
	if(void *mem=malloc(n))
		return mem;
	else
		throw std::bad_alloc();
}
void operator delete(void *mem)noexcept{
	free(mem);
}
int main() {
	
    return 0;
}
