/*Author
	whulinus 1034765650@qq.com
Program
	some string fuctions. 
History
	version 1.0
	2016.5.20
*/
#ifndef MSTRING_H
#define MSTRING_H
#include <string>
inline bool isupper(const std::string &s) {
    for(auto c:s)
        if(isupper(c))
            return true;
    return false;
}
inline void tolower(std::string &s) {
    for(auto &c:s)
        c=tolower(c);
}
#endif 
