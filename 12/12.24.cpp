/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.23
 *History
 *	ver 1.0 2016.7.11
 */
#include <iostream>
#include <fstream>
using namespace::std;
int main(int argc,char* argv[]){
	ifstream in("word.txt");
	char *c3=new char[2]();
	in.get(c3,2);
	cout<<c3<<endl;
	delete [] c3;
	return 0;
}
