/*Author
	whulinus 1034765650@qq.com
Program
	use if statements to count vowel letters(including upper case) from input.
History
	version 1.0
	2016.5.10
*/

#include <iostream>
using namespace std;

int main() {
    char ch;
    unsigned aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
    while(cin>>ch)
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
        }
    cout<<"Number of vowel a: \t"<<aCnt<<'\n'
        <<"Number of vowel e: \t"<<eCnt<<'\n'
        <<"Number of vowel i: \t"<<iCnt<<'\n'
        <<"Number of vowel o: \t"<<oCnt<<'\n'
        <<"Number of vowel u: \t"<<uCnt<<endl;
    return 0;
}
