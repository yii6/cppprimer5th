/*Author
	whulinus 1034765650@qq.com
Program
	Bulk_quote.h
History
	version 1.0 2016.8.1
	version 2.0 2016.8.2
	add abstract base class
	version 3.0 2016.8.7
	add copy control members
*/
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include <iostream>
#include <string>
#include "Quote.h"
class Disc_quote:public Quote {
public:
//friends
//constructors
    Disc_quote()=default;
    Disc_quote(const std::string &book,double price,std::size_t qty,
               double disc):Quote(book,price),min_qty(qty),discount(disc) {
    }
//overloaded assignment operator
//functions
    double net_price(std::size_t )const =0;
protected:
    std::size_t min_qty=0;
    double discount=0.0;
private:
//private functions
};
class Bulk_quote:public Disc_quote {
public:
//friends
//constructors
    Bulk_quote()=default;
    using Disc_quote::Disc_quote;
//copy control members
//copy constructor
    Bulk_quote(const Bulk_quote &b):Disc_quote(b) {
    }
//move constructor
    Bulk_quote(Bulk_quote &&b)noexcept:Disc_quote(std::move(b)) {
    }
//copy-assignment operator
    Bulk_quote &operator=(const Bulk_quote &rhs) {
        Disc_quote::operator=(rhs);
        return *this;
    }
//move-assignment operator
    Bulk_quote &operator=(Bulk_quote &&rhs)noexcept {
        if(this!=&rhs)
            Disc_quote::operator=(rhs);
        return *this;
    }
//destructor
    ~Bulk_quote() {
    }
//overloaded assignment operator
//functions
    double net_price(std::size_t )const override;
    void debug()override {
        std::cout<<min_qty<<" "<<discount<<std::endl;
    }
    Bulk_quote *clone()const & {
        return new Bulk_quote(*this);
    }
    Bulk_quote *clone() && {return new Bulk_quote(std::move(*this));}
private:
//private functions
};
//constructors
//overloaded assignment operator
//public functions
double Bulk_quote::net_price(size_t cnt)const {
    if(cnt>=min_qty)
        return cnt*(1-discount)*price;
    else
        return cnt*price;
}
//private functions
//other functions
#endif

