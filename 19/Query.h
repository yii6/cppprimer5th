/*Author
	whulinus 1034765650@qq.com
Program
	Quary.h
History
	version 1.0 2016.8.10
	version 2.0 2016.10.8
	using namespace
*/
#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <iterator>
#include <algorithm>
#include "TextQuery.h"
namespace chapter15 {
    class Query_base {
    public:
//friends
        friend class Query;
    protected:
        using line_no=std::vector<std::string>::size_type;
        virtual ~Query_base()=default;
    private:
//private functions
        virtual QueryResult eval(const TextQuery &)const=0;
        virtual std::string rep()const=0;
    };
    
    class WordQuery:public Query_base {
    public:
//friends
        friend class Query;
//constructors
        WordQuery(const std::string &s):query_word(s) {
            std::cout<<"word query constructor"<<std::endl;
        }
    private:
        std::string query_word;
//private functions
        QueryResult eval(const TextQuery &t) const {
            std::cout<<"WordQuery eval"<<std::endl;
            return t.query(query_word);
        }
        std::string rep()const {
            std::cout<<"WordQuery:"<<query_word<<std::endl;
            return query_word;
        }
    };
    
    class Query {
    public:
//friends
        friend Query operator~(const Query &);
        friend Query operator|(const Query &,const Query &);
        friend Query operator&(const Query &,const Query &);
        friend std::ostream &operator<<(std::ostream &,const Query &);
//constructors
        Query(const std::string &s):q(new WordQuery(s)) {
            std::cout<<"query constructor"<<std::endl;
        }
//functions
        QueryResult eval(const TextQuery &t)const {
            std::cout<<"query eval"<<std::endl;
            return q->eval(t);
        }
        std::string rep()const {
            std::string s=q->rep();
            std::cout<<"Query:"<<s<<std::endl;
            return s;
        }
    private:
        Query(Query_base *query):q(query) {
        }
        Query_base *q;
//private functions
    };
    std::ostream &operator<<(std::ostream &,const Query &);
    inline Query operator~(const Query &) ;
    inline Query operator&(const Query &,const Query &) ;
    inline Query operator|(const Query &,const Query &);
    TextQuery get_file(int,char **);
    
	class NotQuery:public Query_base {
    public:
//friends
        friend Query operator~(const Query &);
//constructors
        NotQuery(const Query &q):query(q) {
            std::cout<<"~query constructor"<<std::endl;
        }
//functions
        QueryResult eval(const TextQuery &)const;
        std::string rep()const {
            std::string s="~("+query.rep()+")";
            std::cout<<"NotQuery:"<<s<<std::endl;
            return s;
        }
    private:
        Query query;
    };
    
    class BinaryQuery:public Query_base {
    protected:
//constructors
        BinaryQuery(const Query &l,const Query &r,std::string s):lhs(l),rhs(r),
            opSym(s) {
            std::cout<<"binaryquery constructor"<<std::endl;
        }
//functions
        std::string rep()const {
            std::string s="("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";
            std::cout<<"BinaryQuery:"<<s<<std::endl;
            return s;
        }
//data members
        Query lhs,rhs;
        std::string opSym;
    private:
//private functions
    };
    
    class AndQuery:public BinaryQuery {
    public:
//friends
        friend Query operator&(const Query &,const Query &);
//constructors
        AndQuery(const Query &l,const Query &r):BinaryQuery(l,r,"&") {
            std::cout<<"&query constructor"<<std::endl;
        }
//functions
        QueryResult eval(const TextQuery &)const;
    private:
    };
    
    class OrQuery:public BinaryQuery {
    public:
//friends
        friend Query operator|(const Query &,const Query &);
//constructors
        OrQuery(const Query &l,const Query &r):BinaryQuery(l,r,"|") {
            std::cout<<"|query constructor"<<std::endl;
        }
//functions
        QueryResult eval(const TextQuery &)const;
    };
}
#endif

