/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	TextQuery.h
 *History
 *	ver 1.0 2016.7.12
 *	ver 2.0 2016.10.22
  	use nested class
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
std::string make_plural(std::size_t ctr,const std::string &word,
                        const std::string &ending) {
    return (ctr>1)?word+ending:word;
}

class TextQuery {
public:
	class QueryResult;
    using line_no=std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
//functions
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;
//private functions 
    static std::string cleanup_str(const std::string&);
};
std::string TextQuery::cleanup_str(const std::string &word){
    std::string ret;
    for (auto it = word.begin(); it != word.end(); ++it) 
        if (!ispunct(*it))
            ret += *it;
    return ret;
}
TextQuery::TextQuery(std::ifstream &is):file(new std::vector<std::string>) {
    std::string text;
    while(getline(is,text)) {
        file->push_back(text);
        int n=file->size()-1;
        std::istringstream line(text);
        std::string word;
        while(line>>word) {
        	word = cleanup_str(word);
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}
struct TextQuery::QueryResult {
    typedef std::set<line_no>::const_iterator line_it;
//friends
    friend std::ostream &print(std::ostream &,const QueryResult &);
//constructors
    QueryResult(std::string,std::shared_ptr<std::set<line_no>>,
                std::shared_ptr<std::vector<std::string>>);
//functions
    std::set<line_no>::size_type size() const  {
        return lines->size();
    }
    line_it begin() const {
        return lines->cbegin();
    }
    line_it end() const   {
        return lines->cend();
    }
    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
};
//constructors
TextQuery::QueryResult::QueryResult(std::string s,std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):sought(s),lines(p),file(f) {}
//functions
std::ostream &print(std::ostream &os,const TextQuery::QueryResult &qr) {
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "<<make_plural(qr.lines->size(),
                                                                  "time","s")<<std::endl;
    for(auto num:*qr.lines)
        os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<std::endl;
    return os;
}
TextQuery::QueryResult TextQuery::query(const std::string &sought)const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc=wm.find(sought);
    if(loc==wm.end())
        return QueryResult(sought,nodata,file);
    else
        return QueryResult(sought,loc->second,file);
}
#endif
