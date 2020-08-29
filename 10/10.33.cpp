/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 10.33
History
    version 1.0
    2016.7.2
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;
//use 3 right arguments then won't have run problem.
int main(int argc,char *argv[]) {
    if(argc!=4)
    return -1;
	ifstream in(argv[1]);
    ofstream even_of(argv[3]),odd_of(argv[2]);
    istream_iterator<int> int_ii(in),eof;
    ostream_iterator<int> even_oi(even_of,"\n"),odd_oi(odd_of," ");
    while(int_ii!=eof){
    	if(*int_ii%2)
    	*odd_oi++=*int_ii;
    	else
    	*even_oi++=*int_ii;
    	++int_ii;
	}
    return 0;
}
