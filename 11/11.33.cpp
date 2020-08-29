/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 * 	words transform.
 *History
 *	ver 1.0 2016.7.6
 */
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
map<string,string> buildMap(ifstream &map_file){
	map<string,string> trans_map;
	string key,value;
	while(map_file>>key&&getline(map_file,value))
		if(value.size()>1)
			trans_map[key]=value.substr(1);
		else
			throw runtime_error("no rule for "+key);
	return trans_map;
}
const string & transform(const string &s,const map<string,string> &m){
	auto map_it=m.find(s);
	if(map_it!=m.end())
		return map_it->second;
	else
		return s;
}
void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map=buildMap(map_file);
	string text;
	while(getline(input,text)){
		istringstream stream(text);	
		string word;
		bool fw=true;
		while(stream>>word){
			if(fw)
				fw=false;
			else
				cout<<" ";
			cout<<transform(word,trans_map);
		}
	cout<<endl;
	}
}
int main(int argc,char* argv[]){
	ifstream input("input.txt"),map_file("map_file.txt");
	word_transform(map_file,input);
}
