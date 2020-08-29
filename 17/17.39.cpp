/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 * 	show how to use operators
 *History
 *	ver 1.0 2016.10.1
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc,char *argv[]) {
	fstream inOut("17.39.txt",fstream::ate|fstream::in|fstream::out);
	if(!inOut){
		cerr<<"unable to open file"<<endl;
		return EXIT_FAILURE;
	}
	auto endM=inOut.tellg();
	inOut.seekg(0,fstream::beg);
	size_t cnt=0;
	string line;
	while(inOut&&inOut.tellg()!=endM&&getline(inOut,line)){
		cnt+=line.size()+1;
		auto mark=inOut.tellg();
		inOut.seekp(0,fstream::end);
		inOut<<cnt;
		if(mark!=endM)
			inOut<<" ";
		inOut.seekg(mark);
	} 
	inOut.seekp(0,fstream::end);
	inOut<<"\n";
	return 0;
}
