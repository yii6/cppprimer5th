/*Author
	whulinus 1034765650@qq.com
Program
	Basket.h
History
	version 1.0 2016.8.8
*/
#ifndef BASKET_H
#define BASKET_H
#include <iostream>
#include <memory>
#include <set>
#include "Quote.h"
#include "Bulk_quote.h"

class Basket {
public:
//friends
//constructors
//copy control members
//copy constructor
//move constructor
//copy-assignment operator
//move-assignment operator
//destructor
//overloaded assignment operator
//functions
    double total_receipt(std::ostream &)const;
    void add_item(const Quote &sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(const Quote &&sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn()<rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>,decltype(compare) *> items{compare};
//private functions
};
//constructors
//overloaded assignment operator
//public functions
double Basket::total_receipt(std::ostream &os)const {
    double sum=0.0;
    for(auto iter=items.cbegin(); iter!=items.cend(); iter=items.upper_bound(*iter))
        sum+=print_total(os,**iter,items.count(*iter));
    os<<"Total sale: "<<sum<<std::endl;
    return sum;
}
//private functions
//other functions
#endif

