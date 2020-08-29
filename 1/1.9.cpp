/*Author
	whulinus 1034765650@qq.com
Program
	use while loop to add integers from 50 to 100.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
using namespace std;

int main()
{
    int i=49,sum=0;

    while(++i<101)
        sum+=i;

    cout<<sum<<endl;
    return 0;
}
