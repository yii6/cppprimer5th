#include <iostream>
using namespace std;
#include "Sales_data.h"
int main() {
    Sales_data temp1,temp2;
    double price;
    cin>>temp1.bookNo>>temp1.quantity_sold>>price;
    temp1.revenue=temp1.quantity_sold*price;
    cin>>temp2.bookNo>>temp2.quantity_sold>>price;
    temp2.revenue=temp2.quantity_sold*price;
    if(temp1.bookNo==temp2.bookNo) {
        int total_quantity=temp1.quantity_sold+temp2.quantity_sold;
        double total_revenue=temp1.revenue+temp2.revenue;
        if(total_quantity)
            cout <<temp1.bookNo<<" "<<total_quantity<<" "<<total_revenue/total_quantity<<endl;
        else 
            cout <<temp1.bookNo<<" "<<total_quantity<<" "<<"No sales!"<<endl;
        return 0;
    }
    else {
        cerr <<"Data must refer to same ISBN!"<<endl;
        return -1;
    }
}

