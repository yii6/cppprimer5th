/*Author
	whulinus 1034765650@qq.com
Program
	write a function, of which variables are objects of initializer_list<int> type,
function is calculating the sum of all elements.
History
	version 1.0
	2016.5.17
*/

#include <iostream>
#include <initializer_list>
using namespace std;

int sum(std::initializer_list<int> il){
    int sum = 0;
    for (auto i : il) sum += i;
    return sum;
}

int main(){
    cout << sum({1, 2, 3, 4, 5}) <<endl;
    return 0;
}
