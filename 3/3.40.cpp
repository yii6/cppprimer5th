/*Author
	whulinus 1034765650@qq.com
Program
	use strcpy and strcat to copy the content of two arrays to another one. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char cs1[]="hello ",cs2[]="world!";
    char cs3[ strlen(cs1)+strlen(cs2)+1];
    strcpy(cs3,cs1);
    strcat(cs3,cs2);
    cout<<cs3<<endl;
    return 0;
}
