/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	Token.h
 *History
 *	ver 1.0 2016.10.22
 */
#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "Sales_data.h"
using std::string; 
class Token {
public:
//constructor
    Token():tok(INT),ival{0} {}
//copy constructor
    Token(const Token &);
//move constructor
	Token(Token&&)noexcept;
//copy-assignment operator
    Token &operator=(const Token &);
//move-assignment operator
	Token &operator=(Token &&)noexcept;
//destructor
    ~Token();
//other operator
    Token &operator=(const std::string &);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
private:
    enum{INT,CHAR,DBL,STR} tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };
    Sales_data s;
//private funcs
    void copyUnion(const Token &);
    void moveUnion(Token &);
};
//copy control members
Token::Token(const Token &t):tok(t.tok) {
    copyUnion(t);
}
Token::Token(Token &&t)noexcept:tok(t.tok) {
    moveUnion(t);
}
Token& Token::operator=(const Token &t) {
    if(tok==STR&&t.tok!=STR)
        sval.~string();
    if(tok==STR&&t.tok==STR)
        sval=t.sval;
    else
        copyUnion(t);
    tok=t.tok;
    return *this;
}
Token& Token::operator=(Token &&t)noexcept{
    if(tok==STR&&t.tok!=STR)
        sval.~string();
    else
        moveUnion(t);
    tok=t.tok;
    return *this;
}
Token::~Token() {
    if(tok==STR)
        sval.~string();
}
//other operator
Token &Token::operator=(int i) {
    if(tok==STR)
        sval.~string();
    ival=i;
    tok=INT;
    return *this;
}
Token &Token::operator=(char i) {
    if(tok==STR)
        sval.~string();
    cval=i;
    tok=CHAR;
    return *this;
}
Token &Token::operator=(double i) {
    if(tok==STR)
        sval.~string();
    dval=i;
    tok=DBL;
    return *this;
}
Token &Token::operator=(const std::string &i) {
    if(tok==STR)
        sval=i;
    else
        new(&sval) std::string(i);
    tok=STR;
    return *this;
}
//functions of Token
void Token::copyUnion(const Token &t) {
    switch(t.tok) {
        case Token::INT:
            ival=t.ival;
            break;
        case Token::CHAR:
            cval=t.cval;
            break;
        case Token::DBL:
            dval=t.dval;
            break;
        case Token::STR:
            new(&sval) std::string(t.sval);
            break;
    }
}
void Token::moveUnion(Token &t) {
    switch(t.tok) {
        case Token::INT:
            ival=std::move(t.ival);
            break;
        case Token::CHAR:
            cval=std::move(t.cval);
            break;
        case Token::DBL:
            dval=std::move(t.dval);
            break;
        case Token::STR:
            sval=std::move(t.sval);
            break;
    }
}
#endif
