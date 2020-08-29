/*Author
	whulinus 1034765650@qq.com
Program
	Quary.h
History
	version 1.0 2016.8.10
	version 2.0 2016.10.8
	using namespace
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <iterator>
#include <algorithm>
#include "Query.h"
namespace chapter15 {
//overloaded assignment operator
    std::ostream &operator<<(std::ostream &os,const Query &query) {
        return os<<query.rep();
    }
    inline Query operator~(const Query &q) {
        return new NotQuery(q);
    }
//public functions
    QueryResult NotQuery::eval(const TextQuery &text)const {
        std::cout<<"~query eval"<<std::endl;
        auto result=query.eval(text);
        auto ret_lines=std::make_shared<std::set<line_no>>();
        auto beg=result.begin(),end=result.end();
        auto sz=result.get_file()->size();
        for(size_t n=0; n!=sz; ++n)
            if(beg==end||*beg!=n)
                ret_lines->insert(n);
            else if(beg!=end)
                ++beg;
        return QueryResult(rep(),ret_lines,result.get_file());
    }
//overloaded assignment operator
    inline Query operator&(const Query &l,const Query &r) {
        return new AndQuery(l,r);
    }
//public functions
    QueryResult AndQuery::eval(const TextQuery &text)const {
        std::cout<<"&query eval"<<std::endl;
        auto left=lhs.eval(text),right=rhs.eval(text);
        auto ret_lines=std::make_shared<std::set<line_no>>();
        set_intersection(left.begin(),left.end(),right.begin(),right.end(),
                         inserter(*ret_lines,ret_lines->begin()));
        return QueryResult(rep(),ret_lines,left.get_file());
    }
//overloaded assignment operator
    inline Query operator|(const Query &l,const Query &r) {
        return new OrQuery(l,r);
    }
//public functions
    QueryResult OrQuery::eval(const TextQuery &text)const {
        std::cout<<"|query eval"<<std::endl;
        auto left=lhs.eval(text),right=rhs.eval(text);
        auto ret_lines=std::make_shared<std::set<line_no>>(left.begin(),left.end());
        ret_lines->insert(right.begin(),right.end());
        return QueryResult(rep(),ret_lines,left.get_file());
    }
//other functions
    TextQuery get_file(int i,char **s) {
        std::ifstream cin(s[i]);
        return TextQuery(cin);
    }
}


