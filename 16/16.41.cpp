/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 16.39
History
    version 1.0 2016.9.3
*/
#include <iostream>
#include <string>
using namespace std;
template<typename T>
auto sum(T lhs, T rhs) -> decltype( lhs + rhs) {
    return lhs + rhs;
}
int main() {
    auto s= sum(123456789123456789123456789123456789123456789,
                123456789123456789123456789123456789123456789) ;
    return 0;
}
