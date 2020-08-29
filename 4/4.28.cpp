/*Author
	whulinus 1034765650@qq.com
Program
	print out the size of each built-in type.
History
	version 1.0
	2016.5.6
*/

#include <iostream>
using namespace std;

int main() {
    cout<<"bool:"<<sizeof(bool)<<endl;
    cout<<"char:"<<sizeof(char)<<endl;
	cout<<"int:"<<sizeof(int)<<endl;
	cout<<"short:"<<sizeof(short)<<endl;
	cout<<"wchar_t:"<<sizeof(wchar_t)<<endl;
    cout<<"char16_t:"<<sizeof(char16_t)<<endl;
	cout<<"char32_t:"<<sizeof(char32_t)<<endl;
	cout<<"long:"<<sizeof(long)<<endl;
	cout<<"long long:"<<sizeof(long long)<<endl;
    cout<<"double:"<<sizeof(double)<<endl;
	cout<<"float:"<<sizeof(float)<<endl;
	cout<<"long double:"<<sizeof(long double)<<endl;
	cout<<"unsigned int:"<<sizeof(unsigned int)<<endl;
    return 0;
}
