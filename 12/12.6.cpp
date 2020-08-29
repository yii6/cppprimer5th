/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.6
 *History
 *	ver 1.0 2016.7.8
 */
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
using namespace::std;
vector<int>* nvi(){
	return new vector<int>;
}
void rv(vector<int> *(&nvi),istream &is){
	int tmp;
	while(is>>tmp)
		(*nvi).push_back(tmp);
}
void pv(vector<int> *(&nvi)){
	for(auto c:*nvi)
		cout<<c<<" ";
}
int main(int argc,char* argv[]){
	ifstream in("numbers.txt");
	vector<int>* vi=nvi();
	rv(vi,in);
	pv(vi);
	delete(vi);
	return 0;
}
