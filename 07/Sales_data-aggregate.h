/*Author
	whulinus 1034765650@qq.com
Program
	aggregate class header.
History
	version 1.0
	add delegating constructor
	2016.6.10
*/
#ifndef SALES_DATA_AGGREGATE_H
#define SALES_DATA_AGGREGATE_H
#include <string>

struct Sales_data {
        std::string bookNo;
        int quantity_sold;
        double revenue;
};
#endif

