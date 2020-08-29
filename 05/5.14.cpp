/*Author
	whulinus 1034765650@qq.com
Program
	find words that repeat and count how many times it repeats from input.
History
	version 1.0
	2016.5.11
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string line,preword,mostword;
    unsigned cnt=0,max=0;
    while(cin>>line)
        if(preword==line)
            ++cnt;
        else {
            if(cnt>max){
            	max=cnt;
            	mostword=preword;
			}
            cnt=1;
            preword=line;
        }
    if(max<2)
        cout<<"No words have repeated."<<endl;
    else
        cout<<mostword<<" repeated "<<max<<" times."<<endl;
    return 0;
}
