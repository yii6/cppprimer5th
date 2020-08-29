/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 * 	show how to use operators
 *History
 *	ver 1.0 2016.10.1
 */
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]) {
	ifstream in("17.37.txt");
	char sink[12];
	char delim='\n';
	while(in.getline(sink,12,delim))
		cout.write(sink,12);
}
