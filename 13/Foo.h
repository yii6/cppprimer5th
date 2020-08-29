/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	Foo.h
 *History
 *	ver 1.0 2016.7.22
 */
#ifndef FOO_H
#define FOO_H
#include <iostream>
#include <vector>
#include <algorithm>
class Foo {
public:
//friends
//constructor
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
	std::sort(ret.data.begin(),ret.data.end());
	return ret;
}
#endif
