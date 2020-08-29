/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	exxercise 13.56 
 *History
 *	ver 1.0 2016.7.22
 */
#include <iostream>
#include <vector>
#include <algorithm>
class Foo {
public:
//friends
//constructor
	Foo(std::vector<int> v):data(v){
	} 
//copy constructor
//copy-assignment operator
//move-assignment operator
//destructor
//functions
	Foo sorted() &&;
	Foo sorted() const &;
private:
	std::vector<int> data;
//private functions
};
//copy control members
//functions
Foo Foo::sorted()&&{
	std::sort(data.begin(),data.end());
	return *this;
}
Foo Foo::sorted()const &{
	Foo ret(*this);
	std::cout<<"lvalue"<<std::endl;
	return ret.sorted();
}
int main(){
	Foo f({1,23});
	f.sorted();
	return 0;
}

