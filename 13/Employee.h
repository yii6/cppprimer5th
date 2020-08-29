/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	employee.h
 *History
 *	ver 1.0 2016.7.16
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
class Employee{
	std::string name;
	static int no;
	int eNo;
public:
	Employee(){eNo=no;++no;}
	Employee(const std::string &s):name(s){eNo=no;++no;}
	Employee(const Employee &n){eNo=n.eNo+1;}
	Employee& operator=(const Employee &ne){return *this;}
};
int Employee::no=1;
#endif
