/*Author
	whulinus 1034765650@qq.com
Program
	input two integers x,y, use try-statement to catch exception.
History
	version 1.0
	2016.5.12
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int x,y;
    cout<<"Enter two integers x and y, the output is x/y:"
    while(cin>>x>>y) {
        try {
            if(y==0)
                throw runtime_error("divisor can't be 0.");
            cout<<x/y<<endl;
        }
        catch(runtime_error err) {
            cout<<err.what()
                <<"\nTry again? Enter y or n"<<endl;
            char c;
            cin>>c;
            if(!cin||c=='n')
                break;
        }
    }
    return 0;
}
