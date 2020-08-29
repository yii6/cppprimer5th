/*Author
	whulinus 1034765650@qq.com
Program
	Quote.h
History
	version 1.0 2016.8.1
	version 2.0 2016.8.7
	add copy control members
*/
#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <string>

class Quote {
public:
//friends
//constructors
    Quote()=default;
    Quote(const std::string &book,double sales_price):bookNo(book),
        price(sales_price) {
    }
//copy control members
//copy constructor
    Quote(const Quote &q):price(q.price),bookNo(q.bookNo) {
    }
//move constructor
    Quote(Quote &&q)noexcept {
        bookNo=std::move(q.bookNo);
        price=std::move(q.price);
    }
//copy-assignment operator
    Quote &operator=(const Quote &rhs) {
        price=rhs.price;
        bookNo=rhs.bookNo;
        return *this;
    }
//move-assignment operator
    Quote &operator=(Quote &&rhs)noexcept {
        if(this!=&rhs) {
            bookNo=std::move(rhs.bookNo);
            price=std::move(rhs.price);
        }
        return *this;
    }
//destructor
    virtual ~Quote() {
    }
//overloaded assignment operator
//functions
    std::string isbn()const {
        return bookNo;
    }
    virtual double net_price(std::size_t n)const {
        return n*price;
    }
    virtual void debug() {
        std::cout<<price<<std::endl;
    }
    virtual Quote* clone()const &{return new Quote(*this);}
    virtual Quote* clone()&&{return new Quote(std::move(*this));}
private:
    std::string bookNo;
//private functions
protected:
    double price=0.0;
};
//constructors
//overloaded assignment operator
//public functions
//private functions
//other functions
double print_total(std::ostream &os,const Quote &item,size_t n) {
    double ret=item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<std::endl;
    return ret;
}
#endif

