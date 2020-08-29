#include <iostream>
using namespace std;
#include "Sales_data.h"
int main() {
    Sales_data temp;
    while(cin>>temp.bookNo>>temp.quantity_sold>>temp.revenue) {
        cout <<temp.bookNo<<" "<<temp.quantity_sold<<" "<<temp.revenue<<endl;
    }
    return 0;
}

