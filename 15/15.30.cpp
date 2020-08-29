/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 15.20
History
    version 1.0
    2016.8.4
*/
#include <iostream>
#include "Basket.h"
using namespace std;
int main(int argc,char *argv[]) {
    Basket bsk;
	bsk.add_item(Bulk_quote("isbn-abc",50.4,19,0.2));
	bsk.add_item(Bulk_quote("isbn-9108",50.4,19,0.2));
	bsk.add_item(Quote("isbn",50.4));
	bsk.total_receipt(cout);
    return 0;
}
