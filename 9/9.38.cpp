/*  
Author
	whulinus 1034765650@qq.com
Program
	write program to find how vector grows.
History
	version 1.0
	2016.6.25
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
    vector<int> vi;
    int i=0;
    while(++i<59){
    	cout<<vi.size()<<" "<<vi.capacity()<<endl;
    	vi.push_back(i);
	}
    return 0;
}
