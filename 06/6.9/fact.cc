/*Author
	whulinus 1034765650@qq.com
Program
	understand how my compiler supports separate compilation. 
History
	version 1.0
	2016.5.13
*/
#include "Chapter6.h"
int fact(int val) {
    if(val==1||val==0)
        return 1;
    return val*fact(val-1);
}
