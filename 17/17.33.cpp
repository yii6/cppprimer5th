/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 * 	words transform.
 *History
 *	ver 1.0 2016.7.6
 *	ver 2.0 2016.9.30
 *	permit to have several ways for a word to transform, choose one randomly to
 *do the real transform
 */
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime> 
using namespace std;
map<string,vector<string>> buildMap(ifstream &map_file){
	map<string,vector<string>> trans_map;
	string key,value;
	while(map_file>>key&&getline(map_file,value))
		if(value.size()>1)
			trans_map[key].push_back(value.substr(1));
		else
			throw runtime_error("no rule for "+key);
	return trans_map;
}
const string & transform(const string &s,const map<string,vector<string>> &m){
	auto map_it=m.find(s);
	if(map_it!=m.end()){
		static default_random_engine e(time(0)+1);
		uniform_int_distribution<unsigned> u(0,map_it->second.size()-1);
		cout<<"u(e):"<<u(e)<<endl;
		return map_it->second[u(e)];
	}
	else
		return s;
}
void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map=buildMap(map_file);
	//*
	for(auto map_it=trans_map.begin();map_it!=trans_map.end();++map_it){
		cout<<map_it->first<<" ";
		for(auto &d:map_it->second)
		cout<<d<<" ";
		cout<<endl;
	}
	//*/
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
