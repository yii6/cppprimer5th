/*Author
	whulinus 1034765650@qq.com
Program
	header with constructor.
History
	version 1.0 2016.5.22
	version 2.0 2016.5.28
	add some constructor
	version 2.1 2016.5.28
	put the constructor definition which accepts only one istream parameter inside the struct.
	version 3.0 2016.5.30
	access specifiers and friend
	version 4.0 2016.6.8
	add delegating constructor
	version 4.1 2016.6.14
	delete output of calling delegating constructor.
	version 5.0 2016.7.23
	add overloaded assignment operator
*/
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
class Sales_data {
public:
//friends
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &,const Sales_data &);
    friend class std::hash<Sales_data>;
//constructors
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),quantity_sold(n),
        revenue(p*n) {}
    Sales_data(const std::string &s):Sales_data(s,0,0) {}
    Sales_data():Sales_data("",0,0) {}//Sales_data()=default;
    Sales_data(std::istream &);
//overloaded assignment operator
    Sales_data &operator+=(const Sales_data &);
//functions
    std::string isbn() const {
        return bookNo;
    }
private:
    std::string bookNo;
    int quantity_sold;
    double revenue;
//private functions
    double avg_price() const;
};
//constructors delegate to default constructor
Sales_data::Sales_data(std::istream &is) : Sales_data() {
    is >> *this;
}
//overloaded operator members
Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    quantity_sold+=rhs.quantity_sold;
    revenue+=rhs.revenue;
    return *this;
}
//other overloaded operator
std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.quantity_sold << " " << item.revenue << " "
       << item.avg_price();
    return os;
}
std::istream &operator>>(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.quantity_sold >> price;
    if (is)
        item.revenue = price * item.quantity_sold;
    else
        item = Sales_data();
    return is;
}
Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs) {
    Sales_data sum=lhs;
    sum+=rhs;
    return sum;
}
bool operator==(const Sales_data &l,const Sales_data &r){
	return l.isbn()==r.isbn();
}
bool operator<(const Sales_data &l,const Sales_data &r){
	return l.isbn()<r.isbn();
}
//private functions
inline double Sales_data::avg_price() const {
    if(quantity_sold)
        return revenue/quantity_sold;
    else
        return 0;
}

//other codes
namespace std{
	template<> struct hash<Sales_data>{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s)const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data &s)const{
		return hash<string>()(s.bookNo)^hash<int>()(s.quantity_sold)^hash<double>()(s.revenue);
	}
}
#endif

