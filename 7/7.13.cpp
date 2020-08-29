/*Author
	whulinus 1034765650@qq.com
Program
	use istream constructor to rewrite transaction processing program..
History
	version 1.0
	2016.5.28
*/
#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
    Sales_data total(cin);
    if(!total.isbn().empty()) {
        while(cin) {
            Sales_data trans(cin);//如果没有数据，trans还是会被默认初始化 
            if(trans.isbn().empty()) break; 
            if(total.isbn()==trans.isbn())
                total.combine(trans);
            else {
                print(cout,total)<<endl;
                total=trans;
            }
        }
        print(cout,total)<<endl;
    }
    else {
        cerr<<"No data!"<<endl;
        return -1;
    }
    return 0;
}
