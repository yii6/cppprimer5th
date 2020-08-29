/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.23
 *History
 *	ver 1.0 2016.7.11
 */
#include <memory>
#include <iostream>
#include <string>
#include <cstring>
using namespace::std;
int main(int argc,char* argv[]){
	char c1[]="abc",c2[]="efg";
	char *c3=new char[7]();
	strcat(c3,c1);
	strcat(c3,c2);
	cout<<c3<<endl;
	delete [] c3;
	string s1(c1),s2(1,'e');
	unique_ptr<string[]> uc2(new string[1]{s1+s2});
	cout<<uc2[0];  
	return 0;
}
