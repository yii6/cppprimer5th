/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	text query.
 *History
 *	ver 1.0 2016.7.12
 */
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

void runQuery (ifstream &infile){
	ifstream in("word.txt");
	vector<string> data;
	map<string,set<int>> wms;
	string line;
	int i=0;
	while(getline(infile,line)){
			data.push_back(line);
			istringstream record(line);
			string words;
			while(record>>words)
				wms[words].insert(i);
			++i;
	}
	do{
		cout<<"enter word to look for, or q to quit: "<<endl;
		string s;
		if(!(in>>s)||s=="q") break;
		cout<<s<<" occurs "<<wms[s].size()<<" times"<<endl;
		for(auto c:wms[s])
		cout<<"(line "<<c<<") "<<data[c]<<endl;
	}while(true);
}

int main(int argc,char* argv[]){
	ifstream rin("essay.txt");
	runQuery(rin);
	return 0;
}
