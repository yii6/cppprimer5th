/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	exercise 12.7
 *History
 *	ver 1.0 2016.7.8
 */
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
using namespace::std;
shared_ptr<vector<int>>  nvi(){
	return make_shared< vector<int>>();
}
void rv(shared_ptr<vector<int>> &nvi,istream &is){
	int tmp;
	while(is>>tmp)
		(*nvi).push_back(tmp);
}
void pv(shared_ptr<vector<int>> &nvi){
	for(auto c:*nvi)
		cout<<c<<" ";
}
int main(int argc,char* argv[]){
	ifstream in("numbers.txt");
	shared_ptr<vector<int>> vi=nvi();
	rv(vi,in);
	pv(vi);
	return 0;
}
