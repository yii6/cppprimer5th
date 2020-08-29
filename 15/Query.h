/*Author
	whulinus 1034765650@qq.com
Program
	Quary.h
History
	version 1.0 2016.8.10
*/
#ifndef QUARY_H
#define QUARY_H
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <iterator>
#include <algorithm>
#include "TextQuery.h"
class Query_base {
public:
//friends
    friend class Query;
//constructors
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
//functions
protected:
    using line_no=std::vector<std::string>::size_type;
    virtual ~Query_base()=default;
private:
//private functions
    virtual QueryResult eval(const TextQuery &)const=0;
    virtual std::string rep()const=0;
};
//constructors
//overloaded assignment operator
//public functions
//private functions
//other functions
class WordQuery:public Query_base {
public:
//friends
    friend class Query;
//constructors
    WordQuery(const std::string &s):query_word(s) {
    	std::cout<<"word query constructor"<<std::endl;
    }
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
//functions
protected:
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
//constructors
//overloaded assignment operator
//public functions
//private functions
//other functions
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
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
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
protected:
private:
    Query(Query_base* query):q(query) {
    }
    Query_base* q;
//private functions
};
//constructors
//overloaded assignment operator
std::ostream &operator<<(std::ostream &os,const Query &query) {
    return os<<query.rep();
}
//public functions
//private functions
//other functions

class NotQuery:public Query_base {
public:
//friends
    friend Query operator~(const Query &);
//constructors
    NotQuery(const Query &q):query(q) {
    	std::cout<<"~query constructor"<<std::endl;
    }
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
//functions
    QueryResult eval(const TextQuery &)const;
    std::string rep()const {
    	std::string s="~("+query.rep()+")";
        std::cout<<"NotQuery:"<<s<<std::endl;
        return s;
    }
protected:
private:
    Query query;
//private functions
};
//constructors
//overloaded assignment operator
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
//private functions
//other functions
class BinaryQuery:public Query_base {
public:
//friends
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
protected:
//constructors
    BinaryQuery(const Query &l,const Query &r,std::string s):lhs(l),rhs(r),
        opSym(s) {std::cout<<"binaryquery constructor"<<std::endl;
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
//constructors
//overloaded assignment operator
//public functions
//private functions
//other functions
class AndQuery:public BinaryQuery {
public:
//friends
    friend Query operator&(const Query &,const Query &);
//constructors
    AndQuery(const Query &l,const Query &r):BinaryQuery(l,r,"&") {
    	std::cout<<"&query constructor"<<std::endl;
    }
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
//functions
    QueryResult eval(const TextQuery &)const;
protected:
private:
//data members
//private functions
};
//constructors
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
//private functions
//other functions
class OrQuery:public BinaryQuery {
public:
//friends
    friend Query operator|(const Query &,const Query &);
//constructors
    OrQuery(const Query &l,const Query &r):BinaryQuery(l,r,"|") {
    	std::cout<<"|query constructor"<<std::endl;
    }
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
//functions
    QueryResult eval(const TextQuery &)const;
protected:
private:
//data members
//private functions
};
//constructors
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
//private functions
//other functions
std::ifstream &open_file(std::ifstream &,const std::string &);
TextQuery get_file(int i,char **s){
	std::ifstream cin(s[i]);
	return TextQuery(cin);
}
bool get_word(std::string &);
bool get_words(std::string &,std::string &);
#endif

