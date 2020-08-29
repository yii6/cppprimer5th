/*
Author
	whulinus 1034765650@qq.com
Program
	calculate the sum of elements in vector<string>.
History
	version 1.0
	2016.6.28
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
    vector<string> vs{"12","34","56"};
    int i,sum=0;
    double d,dsum=0;
    for(auto c:vs){
    	i=stoi(c);
    	sum+=i;
    	d=stod(c);
    	dsum+=d;
	}
	cout<<sum<<" "<<dsum;
    return 0;
}
