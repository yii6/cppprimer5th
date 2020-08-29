/*Author
	whulinus 1034765650@qq.com
Program
	count "ff""fl""fi" from input.
History
	version 1.0
	2016.5.10
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    unsigned ff=0,fl=0,fi=0;
    while(getline(cin,line))
        for(auto iter=line.begin(); iter!=line.end()-1; ++iter) {
            if(*iter=='f') {
                if(*(iter+1)=='f')
                    ++ff;
                if(*(iter+1)=='i')
                    ++fi;
                if(*(iter+1)=='l')
                    ++fl;
            }
        }
    cout<<"Number of ff: \t"<<ff<<'\n'
        <<"Number of fl: \t"<<fl<<'\n'
        <<"Number of fi: \t"<<fi<<endl;
    return 0;
}
