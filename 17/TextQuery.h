/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	StrBlob.h
 *History
 *	ver 1.0 2016.7.12
 */
#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <tuple>
std::string make_plural(std::size_t ctr,const std::string &word,const std::string &ending) {
    return (ctr>1)?word+ending:word;
}
using line_no=std::vector<std::string>::size_type;
typedef std::tuple<std::shared_ptr<std::vector<std::string>>,std::string,std::shared_ptr<std::set<line_no>>> QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;
};
TextQuery::TextQuery(std::ifstream &is):file(new std::vector<std::string>) {
    std::string text;
    while(getline(is,text)) {
        file->push_back(text);
        int n=file->size()-1;
        std::istringstream line(text);
        std::string word;
        while(line>>word) {
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

std::ostream &print(std::ostream &os,const QueryResult &qr) {
    os<<std::get<1>(qr)<<" occurs "<<std::get<2>(qr)->size()<<" "<<make_plural(std::get<2>(qr)->size(),
                                                                  "time","s")<<std::endl;
    for(auto num:*std::get<2>(qr))
        os<<"\t(line "<<num+1<<") "<<*(std::get<0>(qr)->begin()+num)<<std::endl;
    return os;
}
QueryResult TextQuery::query(const std::string &sought)const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc=wm.find(sought);
    if(loc==wm.end())
    	return std::make_tuple(file,sought,nodata);
    else
    	return std::make_tuple(file,sought,loc->second);	
}
#endif
