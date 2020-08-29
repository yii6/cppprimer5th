/*  
Author
	whulinus 1034765650@qq.com
Program
	write a function that accepts 3 arguments. use iterator and insert, append function to add prefix
 and suffix to the name, return the new string. 
History
	version 1.0
	2016.6.28
*/
#include <iostream>
#include <string> 
#include <fstream>
using namespace std;
string addFix(string &s,const string &prefix,const string &suffix){
	s=" "+s;
	s.insert(0,prefix);
	s+=" ";
	return s.insert(s.size(),suffix);
}
int main(int argc,char *argv[]) {
    ifstream in("9.45.txt");
    //ofstream out("2.txt",ofstream::app);
    string s,prefix,suffix;
	while(getline(in,s)){
		in>>prefix>>suffix;
		cout<<addFix(s,prefix,suffix);
	} 
    return 0;
}
