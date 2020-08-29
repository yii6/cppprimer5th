/*Author
	whulinus 1034765650@qq.com
Program
	rewrite bookshop program.
History
	version 1.0
	2016.7.2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "Sales_item.h"
using namespace std;

int main(int argc,char *argv[]) {
    ifstream in("10.12.txt");
    vector<Sales_item> vs;
    Sales_item data;
    while(in>>data)
        vs.push_back(data);
    sort(vs.begin(),vs.end(),compareIsbn);
    auto beg=vs.begin();
    while(beg!=vs.end()) {
        auto dif=find_if(beg+1,vs.end(),[&](Sales_item &s) {
            return beg->isbn()!=s.isbn();
        });
        cout<<accumulate(beg+1,dif,*beg)<<endl;
        beg=dif;
    }
    return 0;
}
