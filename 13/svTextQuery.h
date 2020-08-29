/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	StrBlob.h
 *History
 *	ver 1.0 2016.7.12
 */
#ifndef SVTEXTQUERY_H
#define SVTEXTQUERY_H
#include <string>
#include <set>
#include <map>
#include <memory>
#include <sstream>
#include <fstream>
#include "StrVec.h"
std::string make_plural(std::size_t ctr,const std::string &word,const std::string &ending) {
    return (ctr>1)?word+ending:word;
}
class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<StrVec> file;
    std::map<std::string,std::shared_ptr<std::set<size_t>>> wm;
};
TextQuery::TextQuery(std::ifstream &is):file(new StrVec) {
    std::string text;
    while(getline(is,text)) {
        file->push_back(text);
        std::istringstream line(text);
        std::string word;
        size_t n=file->size()-1;
        while(line>>word) {
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new std::set<size_t>);
            lines->insert(n);
        }
    }
}
struct QueryResult {
    QueryResult(std::string s,std::shared_ptr<std::set<size_t>> p,
                std::shared_ptr<StrVec> f):sought(s),lines(p),file(f) {}
    friend std::ostream &print(std::ostream &,const QueryResult &);
private:
    std::shared_ptr<StrVec> file;
    std::string sought;
    std::shared_ptr<std::set<size_t>> lines;
};
std::ostream &print(std::ostream &os,const QueryResult &qr) {
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "<<make_plural(qr.lines->size(),
                                                                  "time","s")<<std::endl;
    for(auto num:*qr.lines)
        os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<std::endl;
    return os;
}
QueryResult TextQuery::query(const std::string &str)const {
    static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>);
    auto loc=wm.find(str);
    if(loc==wm.end())
        return QueryResult(str,nodata,file);
    else
        return QueryResult(str,loc->second,file);
}
#endif
