/*Author
	whulinus 1034765650@qq.com
Program
	header with constructor.
History
	version 1.0
	2016.5.22
	version 2.0
	add some constructor
	2016.5.28
	version 2.1
	put the constructor definition which accepts only one istream parameter inside the struct.
	2016.5.28
	version 3.0
	access specifiers and friend
	2016.5.30
	version 4.0
	add delegating constructor
	2016.6.8
*/
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
struct Sales_data;
std::istream &read(std::istream &is,Sales_data &data);
class Sales_data {
        std::string bookNo;
        int quantity_sold;
        double revenue;
        double avg_price() const;
    public:
        std::string isbn() const {return bookNo;}
        Sales_data &combine(const Sales_data &);
        //these are constructors
        Sales_data(const std::string &s,unsigned n,double p):bookNo(s),quantity_sold(n),revenue(p*n) {std::cout<<"three argument.";}
        Sales_data(const std::string &s):Sales_data(s,0,0) {std::cout<<"one argument.";}
        //Sales_data()=default;
        Sales_data():Sales_data("",0,0) {std::cout<<"default.";}
		Sales_data(std::istream &is):Sales_data() {read(is,*this); std::cout<<"istream.";}
        friend std::ostream &print(std::ostream &,const Sales_data &);
        friend std::istream &read(std::istream &,Sales_data &);
        friend Sales_data add(const Sales_data &,const Sales_data &);
};
std::ostream &print(std::ostream &os,const Sales_data &data) {
    os<<data.bookNo<<" "<<data.quantity_sold<<" "<<data.revenue<<" "
      <<data.avg_price()<<std::endl;
    return os;
}
std::istream &read(std::istream &is,Sales_data &data) {
    double price=0;
    is>>data.bookNo>>data.quantity_sold>>price;
    data.revenue=price*data.quantity_sold;
    return is;
}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs) {
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}
inline double Sales_data::avg_price() const {
    if(quantity_sold)
        return revenue/quantity_sold;
    else
        return 0;
}
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    quantity_sold+=rhs.quantity_sold;
    revenue+=rhs.revenue;
    return *this;
}
/*
Sales_data:Sales_data(std::istrream &is){
	read(is,*this);
}
//*/
#endif

