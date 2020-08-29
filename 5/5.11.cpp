/*Author
	whulinus 1034765650@qq.com
Program
	use if statements to count vowel letters(including upper case),space,
	tabs and newline from input.
History
	version 1.0
	2016.5.10
*/

#include <iostream>
using namespace std;

int main() {
    char ch;
    unsigned aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0,nCnt=0,
             sCnt=0,tCnt=0;
    while(cin>>noskipws>>ch)//no skip white space 
    	switch(ch) {
            case 'a':case 'A':
                ++aCnt; break;
            case 'e':case 'E':
                ++eCnt;  break;
            case 'i':case 'I':
                ++iCnt;  break;
            case 'o':case 'O':
                ++oCnt;  break;
            case 'u':case 'U':
                ++uCnt;  break;
            case '\t':case '\v':
                ++tCnt;  break;
            case ' ':
                ++sCnt; break;
            case '\n':
                ++nCnt;  break;
        }
cout<<"Number of vowel a: \t"<<aCnt<<'\n'
    <<"Number of vowel e: \t"<<eCnt<<'\n'
    <<"Number of vowel i: \t"<<iCnt<<'\n'
    <<"Number of vowel o: \t"<<oCnt<<'\n'
    <<"Number of vowel u: \t"<<uCnt<<'\n'
    <<"Number of space: \t"<<sCnt<<'\n'
    <<"Number of newline: \t"<<nCnt<<'\n'
    <<"Number of tabs: \t"<<tCnt<<endl;
return 0;
}
