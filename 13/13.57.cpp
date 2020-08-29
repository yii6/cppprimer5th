/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	exxercise 13.57 
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
	Foo():data(std::vector<int>()){
	}
	Foo(std::vector<int> v):data(v){
	} 
//copy constructor
//copy-assignment operator
//move-assignment operator
//destructor
//functions
	Foo sorted() &&;
	Foo sorted() const &;
	void print(){
		for(auto c:data)
	std::cout<<c<<" ";
	std::cout<<std::endl;
	}
private:
	std::vector<int> data;
//private functions
};
//copy control members
//functions
Foo Foo::sorted()&&{
	std::sort(data.begin(),data.end());
	std::cout<<"rvalue"<<std::endl;
	return *this;
}
Foo Foo::sorted()const &{
	std::cout<<"lvalue"<<std::endl;
	return Foo(*this).sorted();
}
int main(){
	Foo f({2,1}),g;
	g=f.sorted();
	f.print();
	g.print();
	return 0;
}

