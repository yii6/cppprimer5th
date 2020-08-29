/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 15.6
History
    version 1.0
    2016.8.1
*/
#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
using namespace std;

int main(int argc,char *argv[]) {
 	Quote basic;
 	Bulk_quote bulk;
 	// cannot declare variable 'dq' to be of abstract type 'Disc_quote'
 	//Disc_quote dq;
 	print_total(cout,basic,20);
 	print_total(cout,bulk,2);
    return 0;
}
